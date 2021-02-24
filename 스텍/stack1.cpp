#include <iostream>
using namespace std;


void push(int num,int pos,int *arr1[]){
    arr1[pos]=&num;
}


int main(void){
    int num;
    cin>>num;
    int target[num];
    int arr[num][2];
    char res[100];
    int resnum=0;
    for(int i=0;i<num;i++){
        arr[i][0]=i+1;
        arr[i][1]=0;
    }
    
    for(int i=0 ; i<num ; i++){
        cout<<arr[i][0];
    }
    
    for(int i=0;i<num;i++){
       cin>>target[i];
    }

    int j=0;
    for(int i=0;i<num;i++){
        
        
        while(arr[j][0]<=target[i]&j<num){
            if(arr[j][1]==0){
                //cout<<"arr[j]: "<<arr[j][0]<<"  j: "<<j<<"  target: "<<target[i]<<" i= "<<i<<"+"<<endl;
                res[resnum]='+';
                resnum++;
                arr[j][1]=1;
            }

            
            else if(arr[j][0]!=target[i]&arr[j][1]!=0&num-1>j){ 
                
                //cout<<"arr[j]: "<<arr[j][0]<<"  j: "<<j<<"  target: "<<target[i]<<" i= "<<i<<"j++"<<endl;
            }
            j++;
            //cout<<"j"<<endl;
        }
        
        while(arr[j-1][0]>=target[i]){
            if(arr[j-1][0]==target[i]){
                    //cout<<"arr[j]: "<<arr[j][0]<<"  j: "<<j<<"  target: "<<target[i]<<" i= "<<i<<"-"<<endl;
                    res[resnum]='-';
                    resnum++;
                    //cout<<"-"<<endl;
                }
            else {
                //cout<<"arr[j]: "<<arr[j][0]<<"  j: "<<j<<"  target: "<<target[i]<<" i= "<<i<<"error"<<endl;
            }
            j--;
        }
        
        }
    
    for(int i=0;i<resnum;i++){
        cout<<res[i]<<endl;
    }
    return 0;
}

