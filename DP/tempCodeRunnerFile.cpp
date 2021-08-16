#include <iostream>

using namespace std;
int main (void){
    int num;
    cin>>num;
    int res = 0;
    int arr[num][num];
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            arr[i][j] = 1001;
        }
    }
    for(int i = 0 ; i < num ; i++){
        cin>>arr[i][0];
    }
    
    for(int i = 0 ; i < num-2 ; i++){
        for(int j = 0 ; j < num ; j++){
            for(int k =j ;k < num ; k++){
                if (arr[j][i] < arr[k][0])
                {
                    arr[j][i + 1] = arr[k][0];
                    break;
                }
            }
        }
    }

    for(int i = 0 ; i < num ; i++){
        for(int j = 0 ; j < num ; j++){
            if(arr[i][j] == 1001){
                res = max(res,j);
                break;
            }
        }
    }
    cout<<res;


}