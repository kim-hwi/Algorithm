#include<iostream>
using namespace std;
int main (void){
    int res=0,pres=0,mres=0;
    char mode='p';
    string number;
    cin>>number;
    char temp[5];
    int tempnow=0;

    for(int i=0;i<number.size();i++){
        if(number[i]=='0'||number[i]=='1'||number[i]=='2'||number[i]=='3'||number[i]=='4'||number[i]=='5'||number[i]=='6'||number[i]=='7'||number[i]=='8'||number[i]=='9'){
            temp[tempnow]=number[i];
            tempnow++;
        }
        
        if(number[i]=='+'){
            if(mode=='p'){
                pres+=stoi(temp);
                for(int j=0;j<5;j++) temp[j]='\0';
                tempnow=0;
            }
            if(mode=='m'){
                mres+=stoi(temp);
                for(int j=0;j<5;j++) temp[j]='\0';
                tempnow=0;
            }
        }
        
        if(number[i]=='-'){
            if(mode=='p'){
                mode='m';
                pres+=stoi(temp);
                for(int j=0;j<5;j++) temp[j]=' ';
                tempnow=0;
            }
            else if(mode=='m')
            {
                //mode='p';
                mres+=stoi(temp);
                for(int j=0;j<5;j++) temp[j]=' ';
                tempnow=0;
            }
        }
        if(number[i]<='0'&number[i]>='9'){

        }
        //cout<<"pres= "<<pres<<"mres="<<mres<<" temp= "<<temp<<" mode= "<<mode<<" number= "<<number[i]<<" i="<<i<<endl;
    }
    if(mode=='m') mres+=stoi(temp);
    else pres+=stoi(temp);
    //cout<<"pres= "<<pres<<"mres="<<mres<<" temp= "<<temp<<" mode= "<<mode<<endl;
    //cout<<number.size()<<endl;
    cout<<pres-mres;
}
    