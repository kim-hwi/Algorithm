#include<iostream>
using namespace std;
int st[301][3];
int main (void){
    int num;
    cin>>num;
    for(int i = 1 ; i < num+1 ; i++) cin>>st[i][0];
    st[1][1]=st[1][0];
    st[1][2]=st[1][0];
    st[2][1]=st[1][1]+st[2][0];
    st[2][2]=st[2][0];
    for(int i = 3 ; i < num+1 ; i++){
            st[i][1]=st[i-1][2]+st[i][0];
            st[i][2]=max(st[i-2][1],st[i-2][2])+st[i][0];
    }
    cout<<max(st[num][1],st[num][2]);
} 