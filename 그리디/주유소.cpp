#include<iostream>
using namespace std;
int main(void){
    long long pay=0;
    int citynum;
    cin>>citynum;
    int cityoil[citynum];
    long long path[citynum-1];
    for(int i=0;i<citynum-1;i++) cin>>path[i];
    for(int i=0;i<citynum;i++) cin>>cityoil[i];
    long long temppath=0;

    for(int i=0;i<citynum;i++){
        temppath=0;
        for(int j=i+1;j<citynum;j++){
            temppath+=path[j-1];
            
            if(j==citynum-1){
                pay+=temppath*cityoil[i];
                cout<<pay;
                //cout<<"finish for i="<<i<<" cityoil[i]= "<<cityoil[i]<<" temppath= "<<temppath<<" pay= "<<pay<<endl;
                return 0;
            }

            if(cityoil[i]>cityoil[j]){
                pay+=temppath*cityoil[i];
                //cout<<"i="<<i<<" j= "<<j<<" cityoil[i]= "<<cityoil[i]<<" cityoil[j]= "<<cityoil[j]<<" temppath= "<<temppath<<" pay= "<<pay<<" path[j-1]= "<<path[j-1]<<endl;
                temppath=0;
                i=j-1;
                break;
            }
            //cout<<"i="<<i<<" j= "<<j<<" cityoil[i]= "<<cityoil[i]<<" cityoil[j]= "<<cityoil[j]<<" temppath= "<<temppath<<" pay= "<<pay<<" path[j-1]= "<<path[j-1]<<endl;
        }
    }
    // for(int i=0;i<citynum;i++){
    //     cout<<"for i="<<i<<" cityoil[i]= "<<cityoil[i]<<" temppath= "<<temppath<<" pay= "<<pay<<endl;
    //     temppath=0;
    //     for(int j=i+1;j<citynum;j++){
    //         temppath+=path[j-1];
    //         cout<<"i="<<i<<" j= "<<j<<" cityoil[i]= "<<cityoil[i]<<" cityoil[j]= "<<cityoil[j]<<" temppath= "<<temppath<<" pay= "<<pay<<" path[j-1]= "<<path[j-1]<<endl;
    //         if(cityoil[i]>=cityoil[j]){
    //             pay+=temppath*cityoil[i];
    //             cout<<"i="<<i<<" j= "<<j<<" cityoil[i]= "<<cityoil[i]<<" cityoil[j]= "<<cityoil[j]<<" temppath= "<<temppath<<" pay= "<<pay<<" inside"<<" path[j-1]= "<<path[j-1]<<endl;
    //             temppath=0;
    //             i=j-1;
    //             break;
    //         }
    //         if(j==citynum-1)
    //         {
    //             pay+=temppath*cityoil[i];
    //             i=j-1;
    //         }
    //     }

    // }
    // if(pay==0) pay=temppath*cityoil[0];
    // cout<<pay; 
}