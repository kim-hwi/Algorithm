#include <iostream>
using namespace std;
int main (void){
    int start,end,res=0,count=0;
    cin>>start>>end; 
    for(int i =1 ; i <= end ; i++){
        for(int j = 0 ; j < i ; j++ ){
            count++;
            if(count>=start && count<=end){
                res+=i;
            }
        }
    }
    cout<<res;
}