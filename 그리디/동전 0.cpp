#include<iostream>
using namespace std;
int main(void){
    int coinea,money,count=0;
    cin>>coinea>>money;
    int coin[coinea];
    for(int i=0;i<coinea;i++){
        cin>>coin[i];
    }
    for(int i=0;i<coinea;i++){
        while(coin[coinea-i-1]<=money){
            money=money-coin[coinea-i-1];
            count++;
        }
    }
    cout<<count;
}