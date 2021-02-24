#include<iostream>
#include<utility>
#include<queue>
using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(void){
    int x,y;
    int ea=0,maxnum=0;
    cin>>x>>y;
    //왜 안에 있으면 값이 다른가?
    int board[x+50][y+50];
    int arr[10][10]={0};
    bool vis[x+50][y+50];
    //cout<<endl<<x<<" "<<y<<endl;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            cin>>board[i][j];
        }
    }
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            if(board[i][j] == 0 || vis[i][j]) continue;
            ea++;
            queue<pair<int,int> > Q;
            vis[i][j]=1;
            Q.push(pair<int,int>(i,j));
            int now=0;
            while(!Q.empty()){
                now++;
                pair<int,int> cur=Q.front();Q.pop();
                for(int dir=0;dir<4;dir++){
                    int nx=cur.first+dx[dir];
                    int ny=cur.second+dy[dir];
                    if(nx < 0 || nx >= x || ny < 0 || ny >= y) continue;
                    if(vis[nx][ny]||board[nx][ny]!=1) continue;
                    vis[nx][ny]=1;
                    Q.push(pair<int,int>(nx,ny));
                    
                }
            
            }
    
        
        maxnum=max(maxnum,now);
        }
    }
    cout<<ea<<endl<<maxnum;
}