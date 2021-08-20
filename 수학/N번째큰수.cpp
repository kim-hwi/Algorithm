#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    int testcase;
    cin >> testcase;
    for(int i = 0 ; i < testcase ; i++){
        int arr[10];
        for(int j = 0 ; j < 10 ; j++){
            cin>>arr[j];
        }
        sort(arr,arr+10);
        cout<<arr[7]<<endl;
    }
    
}