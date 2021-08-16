#include<iostream>
using namespace std;
int main (void){
    int test;
    cin>>test;
    int arr[test];
    for(int i = 0 ; i < test ; i++){
        cin>>arr[i];
    }
    arr.sort()
    for(int i = 0 ; i < test ; i++){
        cout<<arr[i];
    }
}