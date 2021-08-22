#include <iostream>
using namespace std;
int lenth;
int mymax=1000000001;
int mymin=-1000000001;
int num[11];
int ex[4];

void dfs(int res, int count){
    if(count == lenth -1){
        if(res > mymin){
            mymin = res;

        } 
        if(res < mymax){
            mymax = res;
        }
         
        return;
    }
    for(int i = 0 ; i < 4 ; i++){
        if(ex[i] != 0){
            ex[i]--;
            if(i==0) {
                dfs(res + num[count + 1], count + 1);
            }
                
            
            else if(i==1){
                dfs(res - num[count + 1], count + 1);
            }
                

            else if (i == 2){
                dfs(res * num[count + 1], count + 1);
            }
                

            else if (i == 3){
                dfs(res / num[count + 1], count + 1);
            }
                
            ex[i]++;
        }
    }
     
}

int main (void){
    
    cin>>lenth;
    
    for(int i = 0 ; i < lenth ; i++){
        cin >> num[i];
    }

    cin >> ex[0] >> ex[1] >> ex[2] >> ex[3];
    dfs(num[0],0);

    cout << mymin << endl<< mymax;
}


    // for (int i = 0; i < lenth; i++)
    // {
    //     cout<<num[i];
    // }
