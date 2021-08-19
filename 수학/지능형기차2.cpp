#include <iostream>
using namespace std;
int main (void){
    int Mperson;
    int arr[10][2];
    int nowperson=0;
    cin >> arr[0][0] >> arr[0][1];
    Mperson = arr[0][1];
    nowperson = Mperson;
    for(int i = 1 ; i < 10 ; i++)
    {
        cin>>arr[i][0]>>arr[i][1];
        nowperson=nowperson-arr[i][0]+arr[i][1];
        Mperson=max(Mperson,nowperson);
    }
    cout<<Mperson;
    return 0;
}