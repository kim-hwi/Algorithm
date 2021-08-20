#include<iostream>
using namespace std;

int main (void){
    int N,M;
    cin>>N>>M;
    int gb=N*M;
    int Narr[10001];
    int Marr[10001];
    int gy=1;
    int temp = 0;
    bool endflag = 0;

    for (int i = M; i > 0; i--)
    {
        if (M % i == 0){
            if(N%i==0){
                cout<<i<<endl;
                break;
            }
        }
    }

    for(int i = 0 ; i < N ; i++)
    {
        Marr[i]= M * (i+1);
    }

    endflag = 0;

    for (int i = 0; i < M; i++)
    {
        Narr[i] = N * (i+1);
        for (int j = 0; j < N; j++)
        {
            if( Narr[i] == Marr[j] )
            {
                cout << Marr[j] << '\n';
                endflag = 1;
            }
        }
        if (endflag)
        {
            break;
        }
    }
    return 0;
}