#include<iostream>
using namespace std;
int main (void){
    string str;
    int count=0;
    getline (cin, str);
    for(int i=1;i<str.size()-1;i++){
        if(str[i]==' ') count++;   
    }
    if(str==" ") cout<<0;
    else cout<<count+1;
}