#include<iostream>
using namespace std;
int main (void){
    string a="000",b="000",c,d;
    cin>>c>>d;
    for(int i=0;i<3;i++){
        a[2-i]=c[i];
        b[2-i]=d[i];
    }
 
    cout<<max(stoi(a),stoi(b));
}