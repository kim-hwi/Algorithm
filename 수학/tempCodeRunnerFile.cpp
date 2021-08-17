#include <iostream>
using namespace std;
int main (void){
    int N,K;
    cin>>N>>K;
    int res = 0;
    for(int i = 1 ; i < N ; i++){
        if(N%i==0){
            res++;
        }
        if(res==K){
            cout<<i;
            return 0;
        }
    }
    cout<<0;
    return 0;
}