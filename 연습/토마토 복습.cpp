#include<iostream>
#include<utility>
#include<queue>
using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int board[1002][1002];
int dist[1002][1002];
int main (void){
    int x,y;
    cin>>x>>y;
    queue<pair<int,int> >Q;
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            cin>>board[i][j];
            if(board[i][j]==1) Q.push(pair<int,int>(i,j));
            if(board[i][j]==0) dist[i][j]=-1;
        }
    }
    while(!Q.empty()){
        pair<int,int> cur=Q.front(); Q.pop();
        for(int dir=0;dir<4;dir++){
            int nx=cur.first+dx[dir];
            int ny=cur.second+dy[dir];
            if( nx >= y || nx < 0 || ny >= x || ny < 0 ) continue;
            if(dist[nx][ny]>=0) continue;//study
            dist[nx][ny]=dist[cur.first][cur.second]+1;//study
            Q.push(pair<int,int>(nx,ny));//study
        }
    }
    int ans=0;
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            if(dist[i][j]==-1) {
                cout<<-1;
                return 0;
            }
        ans=max(ans,dist[i][j]);
        }
    }
    cout<<ans;
}