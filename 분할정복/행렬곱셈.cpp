#include<iostream>
using namespace std;
int main (void){
    int x1,y1,x2,y2,num=0;
    cin>>x1>>y1;
    int board1[x1][y1];
    for(int i = 0 ; i < x1 ; i++){
        for(int j = 0 ; j < y1 ; j++){
            cin >> board1[i][j];
        }
    }//첫번째 행렬 생성
    cin>>x2>>y2;
    int board2[x2][y2];
    for (int i = 0; i < x2; i++)
    {
        for (int j = 0; j < y2; j++)
        {
            cin >> board2[i][j];
        }
    }//두번째 행렬 생성
    int res[x1*y2];//출력을 쉽게하기 위함
    for(int i = 0 ; i < x1*y2 ; i++) res[i]=0;//초기화필수
    for(int i=0 ; i < x1 ; i++){
        for(int j = 0 ; j < y2 ; j++){
            for(int k = 0 ; k < y1 ; k++){
                res[num]=res[num] + board1[i][k]*board2[k][j];//곱하여 res에 입력
            }
            num++;
        }
    }
    for(int i = 0 ; i < num ; i++) {
        if (i % y2  == 0 && i!=0)//출력시 i==0인 상황 제외
            cout << endl;
        cout << res[i] << " ";
        
    }

}