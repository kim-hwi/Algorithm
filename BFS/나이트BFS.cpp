#include<iostream>
#include<utility>
#include<queue>
using namespace std;
int dx[8]={1,2,2,1,-1,-2,-2,-1};
int dy[8]={-2,-1,1,2,2,1,-1,-2};
//int board[302][302];
int dist[302][302];
int main (void){
    int testcace;
    cin>>testcace;
    int res[testcace];
    int l, nowX, nowY, goalX, goalY;
    for(int test=0 ; test < testcace ; test++)
    {   
        cin>>l;
        cin>>nowX>>nowY;
        cin>>goalX>>goalY;
        
        for (int i = 0; i < 302; i++)
        {
            for (int j = 0; j < 302; j++)
            {
                dist[i][j] = -1;
            }
        }
        queue<pair<int,int> > Q;
        dist[nowX][nowY]=0;
        Q.push(pair<int,int>(nowX,nowY));
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            for(int dir=0 ; dir < 8 ;dir++){
                int nx=cur.first+dx[dir];
                int ny=cur.second+dy[dir];
                if(nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
                if(dist[nx][ny] == -1 || dist[nx][ny]>dist[cur.first][cur.second]+1){
                    Q.push(pair<int, int>(nx, ny));
                    dist[nx][ny] = dist[cur.first][cur.second] + 1;
                }
            }
        }
        // for(int i = 0 ; i<l ; i++){
        //     for(int j=0 ; j<l ; j++){
        //         cout<<dist[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        res[test]=dist[goalX][goalY];





    }
    for(int i=0;i<testcace;i++){
        cout<<res[i]<<endl;
    }
}