#include<iostream>
using namespace std;
int main (void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int testcase,x,y;
    cin>>testcase;
    for(int i=0;i<testcase;i++){
        cin>>x>>y;
        cout<<x+y<<'\n';
    }
}