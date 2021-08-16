#include <iostream>
using namespace std;

int main (void){
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num;
    cin>>num;
    int res;
    int temp = 0;
    int arr[1000001]={-1001};
    int dp[1000001]={0};
    cin >> arr[0];
    dp[0] = arr[0];
    res = dp[0];
    for(int i  = 1 ; i < num ; i++){
        cin>>arr[i];
        if(dp[i-1]<0){
            dp[i] = arr[i];
        }
        else{
            dp[i] = dp[i - 1] + arr[i];
        }
        res=max(res,dp[i]);
    }
    cout<<res;
}

