#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
int dx[6]={1,0,-1,0,0,0};
int dy[6]={0,1,0,-1,0,0};
int dz[6]={0,0,0,0,1,-1};
int board[102][102][102];
int dist[102][102][102];

int main (void){
    int m,n,h;
    queue<tuple<int, int, int>> Q;
    cin>>m>>n>>h;
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                cin>>board[k][j][i];
                if (board[k][j][i] == 1 ) Q.push(tuple<int,int,int>(k,j,i));
                if (board[k][j][i] == 0) dist[k][j][i]=-1;
            }
        }
    }
    while(!Q.empty()){
        auto cur=Q.front() ; Q.pop();
        for(int dir=0 ; dir<6 ; dir++){
                int nx = get<0>(cur) + dx[dir];
                int ny = get<1>(cur) + dy[dir];
                int nz = get<2>(cur) + dz[dir];
                //cout<<"??"<<endl;
                if(nx<0||nx>=m||ny<0||ny>=n||nz<0||nz>=h) continue;
                if(board[nx][ny][nz]!=0||dist[nx][ny][nz]!=-1) continue;
                dist[nx][ny][nz] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)]+1;
                Q.push(tuple<int, int, int>(nx, ny, nz));
                board[nx][ny][nz]=1;
                
        }
    }

    // for (int i = 0; i < h; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         for (int k = 0; k < m; k++)
    //         {
    //             if(dist[k][j][i]!=-1||board[k][j][i]!=0) continue;
    //             Q.push(tuple<int,int,int>(k,j,i));
    //             path=0;
    //             dist[k][j][i]=path;
    //             while(!Q.empty()){
    //                 auto cur=Q.front();Q.pop();
    //                 for(int dir = 0 ; dir < 6 ; dir++){
    //                     int nx = get<0>(cur) + dx[dir];
    //                     int ny = get<1>(cur) + dy[dir];
    //                     int nz = get<2>(cur) + dz[dir];
    //                     if(nx<0||nx>=m||ny<0||ny>=n||nz<0||nz>=h) continue;
    //                     //if(board[nx][ny][nz]!=0||dist[nx][ny][nz]!=-1) continue;
    //                     if (dist[nx][ny][nz] != -1 && (dist[nx][ny][nz] < dist[get<0>(cur)][get<1>(cur)][get<2>(cur)])){
    //                         cout << "dist[nx][ny][nz] = " << dist[nx][ny][nz] << " dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] = " << dist[get<0>(cur)][get<1>(cur)][get<2>(cur)]<<endl; 
    //                         continue;
    //                     }   
                            
    //                     dist[nx][ny][nz]=++path;
    //                     Q.push(tuple<int, int, int>(nx, ny, nz));
    //                     board[nx][ny][nz]=1;
    //                 }
    //             }
    //         }
    //     }
    // }

    // cout<<endl;
    // for(int i=0;i<h;i++){
    //     for(int j=0;j<n;j++){
    //         for(int k=0;k<m;k++){
    //             //cout<<board[k][j][i]<<" ";
    //             cout << dist[k][j][i] << " ";
    //         }
    //     cout<<endl;
    //     }
    // cout<<endl;
    // }
    int ans=0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if(dist[k][j][i] == -1){
                    cout << -1;
                    return 0;
                }
                ans=max(ans,dist[k][j][i]);
            }
            //cout << endl;
        }
        //cout << endl;
    }
    cout<<ans;
}

