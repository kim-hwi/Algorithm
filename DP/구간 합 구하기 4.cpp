#include<iostream>
using namespace std;
int main (void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N,M;
    cin>>N>>M;
    int sum[N+1][2];
    int bound[M][2];
    for(int i = 1 ; i <= N ; i++){
        cin >> sum[i][0];
        sum[i][1] = sum[i - 1][1] + sum[i][0];
    } 
    sum[0][0]=0;
    sum[0][1]=0;
    sum[1][1]=sum[1][0];
    for(int i = 0 ; i < M ; i++) {
        cin >> bound[i][0] >> bound[i][1];
        cout << sum[bound[i][1]][1] - sum[bound[i][0] - 1][1] << '\n';
    }
    
}