#include<iostream>
using namespace std;
int res[1005];
int main (void){
    int n;
    cin>>n;
   
    res[1]=1;
    res[2]=2;
    for(int i = 3 ; i <= n ; i++){
        res[i]=(res[i-1]+res[i-2])%10007;
    }
    cout<<res[n];
}