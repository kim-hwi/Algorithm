#include <iostream>

using namespace std;
int main (void){
    int num;
    cin>>num;
    int res = 0;
    int arr[1001]={0};
    int dp[1001]={0};
    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
        for(int j = 0 ; j < i ; j++){
            if(arr[i]>arr[j]){
                dp[i] = max(dp[i],dp[j]);
            }
            
        }
        dp[i]+=1;
        res = max(res,dp[i]);
    }    
    // for(int i = 0 ; i < num ; i++){
    //     cout<<arr[i]<<' '<<dp[i]<<endl;
    // }
    cout<<res;
}