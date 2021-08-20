#include<iostream>
using namespace std;
int main (void){
    int testcase;
    cin>>testcase;
    int res=0;
    int endflag = false;
    int temp;
    for(int i = 0 ; i < testcase ; i++){
        
        cin>>temp;
        for(int j = 2 ; j < temp ; j++){
            if(temp%j==0){
                endflag = true;
                break;
            }
        }
        if (temp == 1)
        {
            continue;
        }
        if(endflag == true){
            endflag = false;
            continue;
        }
        res++;
        

    }
    cout<<res;
}