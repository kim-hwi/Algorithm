#include<iostream>
#include<utility>
#include<queue>
using namespace std;
bool com[101];
int main (void){
    int x;
    int y;
    cin>>x>>y;
    for(int i=0;i<101;i++){
        com[i]=false;
    }
    com[0]=true;
    int board [y+1][2];
    queue<pair<int,int> > Q;
    for(int i=0;i<y;i++){
        cin>>board[i][0]>>board[i][1];
        if(board[i][0]==1) {
            Q.push(pair<int,int>(board[i][0],board[i][1]));
        }
    }
    while(!Q.empty()){
        pair<int,int> cur=Q.front();
        Q.pop();
        com[cur.first-1]=true;
        com[cur.second-1]=true;
        for(int i=0;i<y;i++){
            if((board[i][1]==cur.first||board[i][0]==cur.first||board[i][1]==cur.second||board[i][0]==cur.second)&&(com[board[i][0]-1]==false||com[board[i][1]-1]==false)) {
            //양방향 그래프이기 때문에 pair의 뒤쪽에서 연결될 때도 표현해 주어야 한다.
            Q.push(pair<int,int>(board[i][0],board[i][1]));
            }
        }
    }
    int count=0;
    for(int i=0;i<x;i++){
        if(com[i]==true) count++;
    }
    cout<<count-1;
}