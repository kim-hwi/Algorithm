#include<iostream>
using namespace std;

void bi (int num, int max){
    if(max<=0) return;
    if(num-max>=0) {
        cout<<"1 "<<num<<"  "<<max<<endl;
        bi(num-max,max/2);
    }
    else {
        cout<<"0 "<<num<<" "<<max<<endl;
        bi(num,max/2);
    }
    return;
}

int main (void){
    int num;
    int max=1;
    num=4;
    while(max<=num){
        max*=2;
    }
    bi(num,max/2);
}