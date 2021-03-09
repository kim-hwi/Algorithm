#include<iostream>
#include<utility>
#include<queue>
using namespace std;
string board[1002];
int dist[1001][1001];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int main (void){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>board[i];
    }
    for (int i = 0; i < n+1; i++){
        for (int j = 0; j < m+1; j++){
            dist[i][j]=-1;
        }
    }

    queue<pair<int,int> > Q;
    queue<pair<int,int> > Q2;
    Q.push(pair<int,int>(0,0));
    dist[0][0]=0;
    while(!Q.empty()){
        auto cur=Q.front();Q.pop();
        for(int dir = 0 ; dir < 4 ; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(dist[nx][ny]!=-1) continue;
            if(board[nx][ny]=='1'&&dist[nx][ny]==-1){
                Q2.push(pair<int,int>(nx,ny));
                dist[nx][ny] = dist[cur.first][cur.second] + 1;
                continue;
            }
            dist[nx][ny]=dist[cur.first][cur.second]+1;
            Q.push(pair<int,int>(nx,ny));
        }
    }
    while (!Q2.empty())
    {
        auto cur = Q2.front();
        Q2.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (board[nx][ny] == '1') continue;
            if (dist[nx][ny] == -1 || dist[nx][ny] > dist[cur.first][cur.second] + 1)
            {
                dist[nx][ny] = dist[cur.first][cur.second] + 1;
                Q2.push(pair<int, int>(nx, ny));
            }
        }
    }

    // cout<<endl;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<" "<<dist[i][j]<<" ";
    //     }
    // cout<<endl;
    // }
    // while(!Q2.empty()){
    //     cout << Q2.front().first << " " << Q2.front().second << endl;

    //     Q2.pop();
    // }
    if (dist[n-1][m-1]==-1){
        cout<<-1;
        return 0;
    }
    cout<<dist[n-1][m-1]+1;
}
