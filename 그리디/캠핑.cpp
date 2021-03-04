#include<iostream>
using namespace std;
int main (void){
    int L,P,V,res,num=0;
    while(1){
        num++;
        res=0;
        cin>>L>>P>>V;
        if(L==0&&P==0&&V==0) return 0;
        while(P<=V){
            V=V-P;
            res=res+L;
        }
        if(V>0){
            res=res+min(L,V);
        }
        cout<<"Case "<<num<<": "<<res<<endl;
    }
}