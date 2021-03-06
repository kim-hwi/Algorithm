#include<iostream>
using namespace std;
int main (void){
    int rea,temp1;
    cin>>rea;
    int arr[rea];
    for(int i=0;i<rea;i++){
        cin>>arr[i];
    }
    int temp2,j;
    int gap = rea / 2;
    while( gap > 0 ) {//쉘 소트 빅오가 N^2이면 시간초과됨, NlogN의 쉘소트를 채용
        for( int i=gap; i<rea; i++ ) {
            temp2= arr[i];
            j = i;
            while( j>=gap && arr[j-gap]<temp2) {
                arr[j] = arr[j-gap];
                j -= gap;
            }
            arr[j]= temp2;
        }
        gap /= 2;
    }
    int moo=0;
    int temp=0;
    int max1=0;
    for(int i=0;i<rea;i++){
        temp=moo;
        moo=arr[i]*(i+1);
        //cout<<"temp= "<<temp<<" moo= "<<moo<<" arr[i]= "<<arr[i]<<endl; 중간확인
        temp=max(moo,temp);
        max1=max(temp,max1);//세개 중 가장 큰 값의 비교는 없을까?
    }
    cout<<max1;
}