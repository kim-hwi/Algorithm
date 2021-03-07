#include<iostream>
#include<utility>
#include<queue>
using namespace std;
string board[26];
bool vis[26][26];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int main (void){
    int num;
    int danEA=0;
    int seq=0;

    cin>>num;
    int EA[626];
    
    for(int i=0;i<num;i++){
        cin>>board[i];
    }
    //cout<<"1"<<endl;
    queue<pair<int,int> > Q;
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            if(board[i][j]=='0'||vis[i][j]==1) continue;
            Q.push(pair<int,int>(i,j));
            vis[i][j]=1;
            int tempEA=1;
            while(!Q.empty()){
                pair<int,int> cur=Q.front(); Q.pop();
                for(int dir=0;dir<4;dir++){
                    int nx=cur.first+dx[dir];
                    int ny=cur.second+dy[dir];
                    if(nx<0||nx>=num||ny<0||ny>=num) continue;
                    if(vis[nx][ny]==1||board[nx][ny]=='0') continue;
                    Q.push(pair<int,int>(nx,ny));
                    vis[nx][ny]=1;
                    tempEA++;
                }
            }
            EA[seq]=tempEA;
            seq++;
        }
    }
    int gap=seq/2;
    int temp2,j;
    while( gap > 0 ) {//쉘 소트 빅오가 N^2이면 시간초과됨, NlogN의 쉘소트를 채용
        for( int i=gap; i<seq; i++ ) {
            temp2= EA[i];
            j = i;
            while( j>=gap && EA[j-gap]>temp2) {
                EA[j] = EA[j-gap];
                j -= gap;
            }
            EA[j]= temp2;
        }
        gap /= 2;
    }
    cout<<seq<<endl;
    //cout<<"2"<<endl;
    for(int i=0;i<seq;i++){
        cout<<EA[i]<<endl;
    }
}