#include<iostream>
#include<utility>
#include<queue>
using namespace std;
string board[1002];
//bool vis[1002][1002];
int distF[1002][1002];
int distJ[1002][1002];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int main (void){
    queue<pair<int,int> > J;
    queue<pair<int,int> > F;
    int x,y;
    cin>>x>>y;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            distF[i][j]=-1;
            distJ[i][j]=-1;
        }
    }

    for(int i=0;i<x;i++){
        cin>>board[i];
    }
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            if(board[i][j]=='J'){
                J.push(pair<int,int> (i,j));
                distJ[i][j]=0;
            }
            if(board[i][j]=='F'){
                F.push(pair<int,int> (i,j));
                distF[i][j]=0;
            } 
        }
    }

    while(!F.empty()){
        pair<int,int> curF=F.front(); F.pop();
        for(int dir=0;dir<4;dir++){
            int Fx= curF.first+dx[dir];
            int Fy= curF.second+dy[dir];
            if(Fx<0||Fx>=x||Fy<0||Fy>=y) continue;
            if(distF[Fx][Fy]>=0||board[Fx][Fy]=='#') continue;
            distF[Fx][Fy]=distF[curF.first][curF.second]+1;
            F.push(pair<int,int>(Fx,Fy));
        }   
    }
    while(!J.empty()){
        pair<int,int> curJ=J.front(); J.pop();
        for(int dir=0;dir<4;dir++){
            int Jx= curJ.first+dx[dir];
            int Jy= curJ.second+dy[dir];
            if(Jx<0||Jx>=x||Jy<0||Jy>=y){
                cout<<distJ[curJ.first][curJ.second]+1<<endl;
                return 0;
            }
            if(distJ[Jx][Jy]>=0||board[Jx][Jy]=='#') continue;
            if(distF[Jx][Jy] != -1 && distF[Jx][Jy] <= distJ[curJ.first][curJ.second]+1) continue;
            distJ[Jx][Jy]=distJ[curJ.first][curJ.second]+1;
            J.push(pair<int,int>(Jx,Jy));
        }
    }
    cout << "IMPOSSIBLE";

    
    
}   
