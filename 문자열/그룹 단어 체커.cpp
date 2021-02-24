#include<iostream>
using namespace std;
int main(void){
    int testcace;
    cin>>testcace;
    int res=testcace;
    string word[testcace];
    for(int i=0;i<testcace;i++){
        cin>>word[i];
    }
    for(int i=0;i<testcace;i++){
        bool check[26]={false,};
        for(int j=0;j<word[i].size();j++){
            if(int(word[i][j-1]-97)!=int(word[i][j]-97)&check[int(word[i][j]-97)]==true) {res--; break;} 
            check[int(word[i][j]-97)]=true;
        }            
    }
    cout<<res;
}