#include<iostream>
#include<utility>
#include<queue>
using namespace std;
char board[502][502];
bool vis[502][502];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int main (void){
    queue<pair<int,int> > Q;
    int x,y;
    cin>>x>>y;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            cin>>board[i][j];
            if(board[i][j]=='W') Q.push(pair<int,int>(i,j));
        }
    }
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            for(int dir=0;dir<4;dir++){
                if(board[i][j]=='W'&&board[i+dx[dir]][j+dy[dir]]=='S'){
                    cout<<0;
                    return 0;
                }
            }
        }
    }

    while(!Q.empty()){
        pair<int,int> cur=Q.front(); Q.pop();
        for(int dir=0;dir<4;dir++){
            int nx=cur.first+dx[dir];
            int ny=cur.second+dy[dir];
            if(nx<0||nx>=x||ny<0||ny>=y) continue;
            if(vis[nx][ny]) continue;
            if(board[cur.first][cur.second]=='S') continue;
            if(board[nx][ny]=='S') board[cur.first][cur.second]='D';
            if(board[nx][ny] != 'S') vis[nx][ny]=1;
            //board[nx][ny]='V';
            Q.push(pair<int,int>(nx,ny));
            
        //     for(int i=0;i<x;i++){
        //         for(int j=0;j<y;j++){
        //             cout<<board[i][j]<<" ";
        //         }
        //     cout<<endl;
        //     }
        // cout<<endl;
        }

    }
    cout<<1<<endl;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            cout<<board[i][j];
        }
    cout<<endl;
    }
}