#include<iostream>
using namespace std;
int main (void){
    int N;
    cin>>N;
    int house[N][3];
    int price[N][3];
    for(int i = 0 ; i < N ; i++) cin>>house[i][0]>>house[i][1]>>house[i][2];
    
    price[0][0] = house[0][0];
    price[0][1] = house[0][1];
    price[0][2] = house[0][2];
    for (int i = 1; i < N; i++)
    {
        price[i][0] = min(price[i - 1][1], price[i - 1][2]) + house[i][0];
        price[i][1] = min(price[i - 1][0], price[i - 1][2]) + house[i][1];
        price[i][2] = min(price[i - 1][0], price[i - 1][1]) + house[i][2];
    }
    int x = min(price[N-1][0],price[N-1][1]);
    cout<<min(x,price[N-1][2]);
}