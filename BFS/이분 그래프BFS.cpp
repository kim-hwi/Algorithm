#include<iostream>
#include<queue>
#include<utility>
using namespace std;
int main (void){
    int testcase;
    int comea,lineea;
    cin>>comea>>lineea;
    int line[lineea][2];
    int com[comea];
    for(int i=0;i<comea;i++) com[i]=0;
    queue<int> Q;
    for(int i=0;i<lineea;i++){
        int x,y;
        cin>>x>>y;
        line[i][0]=min(x,y);
        line[i][1]=max(x,y);
        Q.push(i+1);
    }
    com[0]=1;
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        //if(com[cur==0]) com[cur]=1;
        for(int i = 0 ; i < lineea ; i++){
            if(cur==line[i][0]){
                com[line[i][1]]=-com[cur];
                Q.push(line[i][1]);
                cout<<"this"<<line[i][0]<<endl;
            }
        }
    }
    for (int i = 0; i < comea; i++)
        {
            cout << com[i] << endl;
        }

    // com[0]=1;
    // for(int i=0;i<comea;i++){
    //     for(int j=0 ; j<lineea; j++){
    //         if (i+1==line[j][0]){
    //             if (com[line[j][1]-1]==0) com[line[j][1]-1] = -com[i];
    //             else if(com[line[j][1]-1] != -com[i]){
    //                 for (int i = 0; i < comea; i++)
    //                 {
    //                     cout << com[i] << endl;
    //                 }
    //                 cout<<"NO"<<endl;
    //                 return 0;
    //             }
    //         }
    //     }
    // }
    
}