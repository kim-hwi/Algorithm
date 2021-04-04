#include<iostream>
using namespace std;
int table[1000001];
int path[100001];
int main (void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,now;
    int res=1;
    cin>>n;
    
    now=n;
    table[1]=0;
    for(int x = 2 ; x <= now ; x++){
        table[x] = table[x - 1] + 1;
        path[x] = x - 1;

        if (x % 2 == 0 && table[x] > table[x / 2] + 1)
        {
            table[x] = table[x / 2] + 1;
            path[x] = x / 2;
        }

        if (x % 3 == 0 && table[x] > table[x / 3] + 1)
        {
            table[x]=table[x/3]+1;
            path[x]=x/3;
        }
        

            
        //res++;
        //x--;
    }
    cout<<table[now]<<'\n';
    int cur = now;
    while(1){
        cout << cur <<" ";
        if(cur == 1) break;
        cur = path[cur];
    }
    //for(int i = 1 ; i <= now ; i++) cout<<table[i]<<" ";
    //  int turn=table[now];
    // while(turn<now){
    //     cout<<path[turn]<<" ";
    //     turn=path[turn];
    //}
}
