#include<iostream>
using namespace std;
int main(void){
    string num;
    int sum=0;
    cin>>num;
    for(int i=0;i<num.size();i++){
        if(num[i]=='A'||num[i]=='B'||num[i]=='C') sum+=3;
        if(num[i]=='D'||num[i]=='E'||num[i]=='F') sum+=4;
        if(num[i]=='G'||num[i]=='H'||num[i]=='I') sum+=5;
        if(num[i]=='J'||num[i]=='K'||num[i]=='L') sum+=6;
        if(num[i]=='M'||num[i]=='N'||num[i]=='O') sum+=7;
        if(num[i]=='P'||num[i]=='Q'||num[i]=='R'||num[i]=='S') sum+=8;
        if(num[i]=='T'||num[i]=='U'||num[i]=='V') sum+=9;
        if(num[i]=='W'||num[i]=='X'||num[i]=='Y'||num[i]=='Z') sum+=10;
    }
    cout<<sum;
}