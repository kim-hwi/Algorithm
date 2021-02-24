#include<iostream>
using namespace std;
int table[1048576][2]={0,};
int ea=0;
void hanoi (int n,int from,int by, int to){
    if(n==1) {
        table[ea][0]=from;
        table[ea][1]=to;
        //cout<<from<<" "<<to<<endl;
        ea++;  
    }else{
        hanoi(n-1,from,to,by);
        //cout<<from<<" "<<to<<endl;
        hanoi(n-1,by,from,to);
        table[ea][0]=from;
        table[ea][1]=to;
        ea++;
    }
}

int main (void){
    int num;
    cin>>num;
    hanoi(num,1,2,3);
    cout<<ea<<endl;
    for(int i=0;i<ea;i++){
        printf("%d %d\n",table[i][0],table[i][1]);
    }
    return 0;

}