#include<iostream>
using namespace std;
int main (void){
    int queue[100000];
    int start=0;
    int end=0;
    int testcase;
    cin>>testcase;
    for(int test=0;test<testcase;test++){
        string in;
        cin>>in;
        if(in == "front"){
            if (end == start) cout << -1 <<endl;
            else cout<<queue[start]<<endl;
        }
        if( in == "push"){
            cin>>queue[end];
            end++;
        }
        if (in == "size"){
            cout<<end-start<<endl;
        }
        if (in == "empty"){
            if(end==start) cout<<1<<endl;
            else cout<<0<<endl;
        }
        if (in == "pop"){
            if (end == start) cout << -1<<endl;
            else{
                cout << queue[start]<<endl;
                start++;
            }
        }
        if (in == "back"){
            if (end == start) cout << -1<<endl;
            else cout<<queue[end-1]<<endl;
        }
    }
}