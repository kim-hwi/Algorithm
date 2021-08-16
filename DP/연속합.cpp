#include <iostream>
using namespace std;
int main (void){
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
        dp[i]=dp[i-1]+arr[i];
        temp = 0;
        for(int j = i ; j > 0 ; j--){
            temp +=arr[j];
            res = max(res,temp);
        }

    }
    cout<<res;
}

