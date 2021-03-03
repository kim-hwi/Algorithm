#include<iostream>
#include<utility>
#include<queue>
using namespace std;
int board[52][52];
bool vis[52][52];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int main (void){
    int testcase,m,n,ea,ze;
    cin>>testcase;
    int res[testcase];
    for(int i=0;i<testcase;i++){
    cin>>m>>n>>ea;    
        for(int i=0;i<52;i++){
            for(int j=0;j<52;j++){
                vis[i][j]=false;
                board[i][j]=0;
            }
        }
        for(int i=0;i<ea;i++){
            int x,y;
            cin>>x>>y;
            board[y][x]=1;
        }
        ze=0;

        queue<pair<int,int> > Q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==true || board[i][j]==0) continue;
                ze++;
                Q.push(pair<int,int>(i,j));
                while(!Q.empty()){
                    pair<int,int> cur=Q.front();Q.pop();
                    vis[cur.first][cur.second]=true;
                    for(int dir=0;dir<4;dir++){
                        int nx=cur.first+dx[dir];
                        int ny=cur.second+dy[dir];
                        if(nx<0||nx>=n||ny<0||ny>=m) continue;
                        if(vis[nx][ny]==true||board[nx][ny]==0) continue;
                        vis[nx][ny]=true;
                        Q.push(pair<int,int>(nx,ny));
                //     cout<<endl;
                //     for(int i=0;i<n;i++){
                //         for(int j=0;j<m;j++){
                //             cout<<vis[i][j]<<" ";
                //         }
                //         cout<<endl;
                //     }
                //     cout<<endl;
                    
                //     }
                // cout<<endl<<ze<<endl;
                }
            }
        }

        // cout<<endl;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<vis[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<board[i][j]<<" ";
        //     }
        //     cout<<endl;
        }
        res[i]=ze;
    }
    for(int i=0;i<testcase;i++) cout<<res[i]<<endl;
}