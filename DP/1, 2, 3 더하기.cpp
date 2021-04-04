#include<iostream>
using namespace std;

int table[12];
int main (void)
{
    int testcase,num;
    cin>>testcase;
    table[0]=1;
    table[1]=2;
    table[2]=4;
    for(int i = 0 ; i < testcase ; i++)
    {
        cin>>num;
        for(int j = 3 ; j < num ; j++){
            table[j]=table[j-1]+table[j-2]+table[j-3];
        }
        cout<<table[num-1]<<endl;
    }
}
