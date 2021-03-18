#include<iostream>
using namespace std;
int main (void){
    int testcase;
    string vps;
    char vis[51];
    bool board[51];
    int end = 0;
    cin>>testcase;
    for(int test = 0; test < testcase ; test++){
        cin>>vps;
        for(int i = 0 ; i < 51 ; i++ ) board[i]=false;
        for(int i = 0 ; i < vps.size() ; i++){
            if (vps[i] == '(' && board[end]==false)
            {
                vis[end++] = vps[i];
            }
            if (vps[i] == ')' && board[end] == false)
            {
                
            }
        }
    }

}