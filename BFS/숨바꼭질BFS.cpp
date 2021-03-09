#include<iostream>
#include<queue>
using namespace std;
int dx[3]={1,-1,2};
int board[1000001];
int dist[1000001];
int main (void){
    int s,d;
    cin>>s>>d;
    queue<int> Q;
    Q.push(s);
    for (int i = 0; i < max(s * 2, d * 2); i++)
    {
        dist[i]=-1;
    }
    
    dist[s] = 0;
    while(!Q.empty()){
        auto cur=Q.front(); Q.pop();
        
        for(int dir=0; dir<3 ; dir++){
            int nx;
            if(dir==2) nx=cur*2;
            else nx=cur+dx[dir];
            if(nx<0||nx>=1000001) continue;
            if(dist[nx] != -1 && dist[nx]<=dist[cur]+1) continue;
            dist[nx]=dist[cur]+1;
            Q.push(nx);
            
        }
    }

    // for (int i = 0; i < max(s * 2, d * 2); i++)
    // {
    //     if (i % 5 == 0)
    //         cout << endl;
    //     cout << dist[i] << " ";
        
    // }
    cout<<dist[d];
}