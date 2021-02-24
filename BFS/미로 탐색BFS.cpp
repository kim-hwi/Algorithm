#include<iostream>
#include<utility>
#include<queue>
#include<string>


using namespace std;
string board[502];
int dis[502][502];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int x,y;
int main(void){
    
    cin>>x>>y;

    for(int i=0;i<x;i++){
        cin>>board[i];
    }
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            dis[i][j]=-1;
        }
    }
    
    queue<pair<int,int> > Q;
    Q.push(pair<int,int>(0,0));
    dis[0][0]=0;
    while(!Q.empty()){
        pair<int,int> cur=Q.front(); Q.pop();
        for(int dir=0;dir<4;dir++){
            int nx=cur.first+dx[dir];
            int ny=cur.second+dy[dir];
            if(nx<0||nx>=x||ny<0||ny>=y) continue;
            if(dis[nx][ny] >= 0||board[nx][ny]!='1') continue;
            dis[nx][ny]=dis[cur.first][cur.second]+1;
            Q.push(pair<int,int>(nx,ny));
        }
    }
    cout << dis[x-1][y-1]+1;
}