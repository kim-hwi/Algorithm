#include<iostream>
using namespace std;
int main(void){
    long long pay=0;//1억*1억을 담기위한 변수
    int citynum;
    cin>>citynum;
    int cityoil[citynum];
    long long path[citynum-1];
    for(int i=0;i<citynum-1;i++) cin>>path[i];
    for(int i=0;i<citynum;i++) cin>>cityoil[i];
    long long temppath=0;//매우중요! int형 1억 둘을 곱하는 순간 pay에 들어가기 전에 오버플로우가 발생되기 때문. int=약 21억 까지.

    for(int i=0;i<citynum;i++){
        temppath=0;
        for(int j=i+1;j<citynum;j++){
            temppath+=path[j-1];
            
            if(j==citynum-1){
                pay+=temppath*cityoil[i];
                cout<<pay;
                return 0;
            }
            if(cityoil[i]>cityoil[j]){
                pay+=temppath*cityoil[i];
                temppath=0;
                i=j-1;
                break;
            }
        }
    }
}