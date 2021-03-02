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
            //cout<<endl<<"push "<<board[i][0]<<" "<<board[i][1]<<endl;
        }
    }
    while(!Q.empty()){
        pair<int,int> cur=Q.front();
        cout<<"inside queue1 "<<cur.first<<" "<<cur.second<<endl;
        Q.pop();
        com[cur.first-1]=true;
        com[cur.second-1]=true;
        for(int i=0;i<y;i++){
            if((board[i][1]==cur.first||board[i][0]==cur.first||board[i][1]==cur.second||board[i][0]==cur.second)&&(com[board[i][0]-1]==false||com[board[i][1]-1]==false)) {
            Q.push(pair<int,int>(board[i][0],board[i][1]));
            cout<<"push2 "<<board[i][0]<<" "<<board[i][1]<<endl;
            }
        }
    }
    int count=0;
    for(int i=0;i<x;i++){
        if(com[i]==true) count++;
    }
    cout<<endl;
    for(int i=0;i<x;i++){
        cout<<i<<" "<<com[i]<<endl;
    }
    cout<<count-1;
}