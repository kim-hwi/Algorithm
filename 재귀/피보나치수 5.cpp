#include<iostream>
using namespace std;

int fac (int num){
    if(num==0) return 0;
    if(num==1) return 1;
    if(num==2) return 1;
    
    return fac(num-1)+fac(num-2);
}

int main(void){
    int a;
    cin>>a;
    cout<<fac(a)<<endl;
    return 0;
}
