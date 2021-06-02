#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <time.h>
#include <pthread.h>

#define BUFFER_MAX 45
#define DIRECTION_MAX 45

#define IN 0
#define OUT 1
#define LOW 0
#define HIGH 1

#define POUT_ULTR 23
#define PIN_ULTR 24

#define VALUE_MAX 256 //256?

int distance = 0;

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}

static int GPIOExport(int pin)
{
    char buffer[BUFFER_MAX];
    ssize_t bytes_written;
    int fd;

    fd = open("/sys/class/gpio/export", O_WRONLY);
    if (fd == -1)
    {
        fprintf(stderr, "Failed to open export for writing!\n");
        return (-1);
    }

    bytes_written = snprintf(buffer, BUFFER_MAX, "%d", pin);
    write(fd, buffer, bytes_written);
    close(fd);
    return (0);
}

static int GPIOUnexport(int pin)
{
    char buffer[BUFFER_MAX];
    ssize_t bytes_written;
    int fd;

    fd = open("/sys/class/gpio/unexport", O_WRONLY);
    if (fd == -1)
    {
        fprintf(stderr, "Failed to open unexport for writing!\n");
        return (-1);
    }

    bytes_written = snprintf(buffer, BUFFER_MAX, "%d", pin);
    write(fd, buffer, bytes_written);
    close(fd);
    return (0);
}

static int GPIODirection(int pin, int dir)
{
    static const char s_direcctions_str[] = "in\0out";

    char path[DIRECTION_MAX] = "/sys/class/gpio/gpio%d/direction";
    int fd;

    snprintf(path, DIRECTION_MAX, "/sys/class/gpio/gpio%d/direction", pin);

    fd = open(path, O_WRONLY);
    if (fd == -1)
    {
        fprintf(stderr, "Failed to open gpio direction for writing!\n");
        return (-1);
    }

    if (-1 == write(fd, &s_direcctions_str[IN == dir ? 0 : 3], IN == dir ? 2 : 3))
    {
        fprintf(stderr, "Failed to set direction!\n");
        return (-1);
    }

    close(fd);
    return (0);
}

static int GPIORead(int pin)
{
    char path[VALUE_MAX];
    char value_str[3];
    int fd;

    snprintf(path, VALUE_MAX, "/sys/class/gpio/gpio%d/value", pin);
    fd = open(path, O_RDONLY);
    if (fd == -1)
    {
        fprintf(stderr, "Failed to open gpio value for reading!\n");
        return (-1);
    }

    if (-1 == read(fd, value_str, 3))
    {
        fprintf(stderr, "Failed to read value!\n");
        return (-1);
    }

    close(fd);

    return (atoi(value_str));
}

static int GPIOWrite(int pin, int value)
{
    static const char s_values_str[] = "01";

    char path[VALUE_MAX];
    int fd;

    snprintf(path, VALUE_MAX, "/sys/class/gpio/gpio%d/value", pin);
    fd = open(path, O_WRONLY);
    if (fd == -1)
    {
        fprintf(stderr, "Failed to open gpio value for writing!\n");
        return (-1);
    }

    if (1 != write(fd, &s_values_str[LOW == value ? 0 : 1], 1))
    {
        fprintf(stderr, "Failed to set direction!\n");
        return (-1);
    }

    close(fd);
    return (0);
}

void *ultrawave_thd()
{
    clock_t start_t, end_t;
    double time;
    //Enable GPIO pins
    if (-1 == GPIOExport(POUT_ULTR) || -1 == GPIOExport(PIN_ULTR))
    { // 초음파 익스포트
        printf("gpio export err!\n");
        exit(0);
    }
    // wait for writing to export file
    usleep(100000);

    //Set GPIO directions
    if (-1 == GPIODirection(POUT_ULTR, OUT) || -1 == GPIODirection(PIN_ULTR, IN))
    {
        printf("gpio direction err!\n");
        exit(0);
    }
    //init ultrawave trigger
    GPIOWrite(POUT_ULTR, 0);
    usleep(10000);
    //start
    while (1)
    {
        if (-1 == GPIOWrite(POUT_ULTR, 1))
        {
            printf("gpio write/trigger err\n");
            exit(0);
        }
        //lsec == 1000000ultra_sec, 1ms = 10000ultra_sec
        usleep(10);
        GPIOWrite(POUT_ULTR, 0);
        //printf("hello world\n");
        while (GPIORead(PIN_ULTR) == 0)
        {
            start_t = clock();
        }

        while (GPIORead(PIN_ULTR) == 1)
        {
            end_t = clock();
        }

        time = (double)(end_t - start_t) / CLOCKS_PER_SEC; // ms
        distance = time / 2 * 34000;

        if (distance > 900)
            distance = 900;

        //printf("time : %.4lf\n", time);
        //printf("distance : %d cm\n", distance); //.5lf

        usleep(500000);
    }
    //printf("after while\n");
}

static void usingSocket(int *sock, char *inputServerInfo[], struct sockaddr_in *serv_addr)
{
    *sock = socket(PF_INET, SOCK_STREAM, 0);
    if (*sock == -1) // socket fd == -1
        error_handling("socket() error");

    memset(serv_addr, 0, sizeof(struct sockaddr_in));
    serv_addr->sin_family = AF_INET;
    serv_addr->sin_addr.s_addr = inet_addr(inputServerInfo[1]);
    serv_addr->sin_port = htons(atoi(inputServerInfo[2]));

    if (connect(*sock, (struct sockaddr *)serv_addr, sizeof(struct sockaddr)) == -1)
        error_handling("connect() error");
}

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in *serv_addr = (struct sockaddr_in *)malloc(sizeof(struct sockaddr_in));
    char msg[2];
    char on[2] = "1";
    int start_len;
    int light = 0;

    if (argc != 3)
    {
        printf("Usage : %s <IP> <port>\n", argv[0]);
        exit(1);
    }

    usingSocket(&sock, argv, serv_addr);

    while (1)
    { // 2초마다 시스템이 시작할건지 main파이로 부터 읽기
        sleep(2);
        if ((start_len = read(sock, msg, sizeof(msg))) == -1)
            continue;

        if (strncmp(on, msg, 1) == 0)
            break;
    }
    printf("switch on and system start!!\n");

    pthread_t p_thread[2];
    pthread_create(&p_thread[0], NULL, ultrawave_thd, NULL); // 초음파 센싱 시작

    // main thread
    while (1)
    {
        //if(-1 == write(sock, distance, sizeof(distance)))  // 센싱값 전송
        //    break;

        printf("distance : %d cm\n", distance);
        write(sock, &distance, sizeof(distance));
        printf("send\n");

        //read(sock, msg, sizeof(msg));
        //printf("%s\n", msg);

        sleep(1); // 1초마다 초음파 센싱 결과 전송
    }

    close(sock);
    sleep(10);

    //Disable GPIO pins
    if (-1 == GPIOUnexport(POUT_ULTR))
        return (4);

    return (0);
}