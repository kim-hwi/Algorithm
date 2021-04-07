#include<iostream>
using namespace std;
int main (void){
    int testcase,N;
    cin>>testcase;
    for(int test = 0 ; test < testcase ; test++){
        cin>>N;
        int board[N][N];
        int person[N][5];
        int exit[N][3];
        int num1=0;
        int num2=0;
        for(int i = 0 ; i < N ; i++)
        {
            for(int j = 0 ; j < N ; j++)
            {
                cin>>board[i][j];
                if(board[i][j]==1){
                    person[num1][0]=1;
                    person[num1][1]=i;
                    person[num1][2]=j;
                    num1++;
                }
                if(board[i][j]!=0&&board[i][j]!=1){
                    exit[num2][0]=board[i][j];
                    exit[num2][1]=i;
                    exit[num2][2]=j;
                    num2++;
                }
            }
        }
        for(int i = 0 ; i < num1 ; i++)
        {
            person[i][3] = exit[0][1] - person[i][1] + exit[0][2] - person[i][2];
            person[i][4] = exit[1][1] - person[i][1] + exit[1][2] - person[i][2];
        }        
    }
}

