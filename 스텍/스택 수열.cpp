#include<iostream>
using namespace std;
int main (void){
    int testcase;
    cin>>testcase;
    int test[testcase];
    char res[testcase*3];
    int resnum=0;
    int stack[testcase+1];
    int start = 1;
    int num=1;
    for(int i=0;i<testcase;i++){
        cin>>test[i];
        stack[i]=0;
    }//stack의 값 초기화

    for(int i=0;i<testcase;i++){
        while(test[i] > stack[start-1]){
            res[resnum++]='+';
            stack[start] = num++;
            start++;//num start값으로 스택구성
        }
        while(test[i] <= stack[start-1]){
            res[resnum++] = '-';
            stack[start]=0;

            if (testcase < stack[start - 1])
            {
                cout << "NO" << endl;//범위 외 값
                return 0;
            }
            start--;
        }
    }

    for(int i=0;i<resnum;i++){
        cout<<res[i]<<'\n';
    }
}
