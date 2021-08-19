#include <iostream>
using namespace std;
int main (void){
    int test;
    int temp;
    int num;
    int ea;
    int arr[1000001];
    int arrnum=0;
    cin>>test;
    for(int i = 0 ; i < test ; i++){
        cin>>temp;
        num = 1;
        ea = 0;
        while (true)
        {
            if (temp < num)
            {
                break;
            }
            num *= 2;
            ea+=1;
        }
        num/=2;
        ea-=1;

        // cout << num << " " << ea << " "<<endl;
        for(int j = ea ; j >= 0 ; j--){
            if(temp>=num){
                temp=temp-num;
                arr[arrnum]=j;
                arrnum++;
            }
            num/=2;
        }
        for(int k = arrnum-1 ; k >= 0 ; k--){
            cout<<arr[k]<<" ";
            
        }
        
        cout<<'\n';
    }
}