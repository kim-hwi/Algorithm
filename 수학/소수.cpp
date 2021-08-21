#include <iostream>
using namespace std;
int main (void){
    int start,end,res=-1,min=0;
    bool flag = false;
    bool first = true;
    cin>>start>>end;
    for(int i = start ; i <= end ; i++){
        if(i == 1 ){
            continue;
        }
        for(int j = 2 ; j < i ; j++){
            if(i%j==0){
                flag = true;
                break;
            }
        }
        if(flag == true){
            flag = false;
            continue;
        }
        if(first == true){
            min = i;
            first = false;
            res+=1;
        }
        res+=i;
    }
    cout<<res<<endl;;
    if(first == false) cout << min;
}