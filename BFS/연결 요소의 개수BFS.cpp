#include<iostream>
#include<utility>
#include<queue>
using namespace std;
//int com[1002];
bool vis[1002];
int conn[1000002][2];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(void){
    int comea,connea,x,y;
    bool inside=false;
    cin>>comea>>connea;
    for(int i=0;i<connea;i++){
        cin>>x>>y;
        conn[i][0]=min(x,y);
        conn[i][1]=max(x,y);
    }
    double ea=0;
    queue<pair<int,int> > Q;
    for(int i=0;i<comea;i++){
        for(int j=0;j<connea;j++){
            if(( i == conn[j][0] ) && ( vis[conn[j][1]] == false )){
                Q.push(pair<int,int>(conn[j][0],conn[j][1]));
                vis[i]=1;
                //cout<<"i= "<<i<<" "<<conn[j][0]<<" "<<conn[j][1]<<" ea "<<ea<<endl;
            }
            else {
                //cout<<"continue i= "<<i<<" "<<conn[j][0]<<" "<<conn[j][1]<<" ea "<<ea<<endl;
                continue;
            }
        
            if(Q.empty()){
                cout<<"finish"<<endl;
                continue;
            } 
            while(!Q.empty()){
                pair<int,int> cur=Q.front(); Q.pop();
                for(int j=0;j<connea;j++){
                    if((cur.second==conn[j][0]||cur.second==conn[j][1])&&(vis[conn[j][0]] == false || vis[conn[j][1]] == false )){
                        Q.push(pair<int,int>(conn[j][0],conn[j][1]));
                        vis[cur.second]=1;
                        vis[conn[j][0]]=1;
                        vis[conn[j][1]]=1;
                        //cout<<"inside i= "<<i<<" cur.secound= "<<cur.second<<" "<<conn[j][0]<<" "<<conn[j][1]<<" ea "<<ea<<endl;
                        inside=true;
                    }
                }
            }
        }
        if(inside==true){
            ea++;
            inside=false;
        }
        //cout<<ea<<endl;
    }
    // cout<<endl;
    // for(int i=0;i<connea;i++){
    //     cout<<conn[i][0]<<" "<<conn[i][1]<<endl;
    // }
    cout<<ea;
}