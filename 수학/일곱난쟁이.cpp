#include <iostream>
#include <algorithm>
using namespace std;
int main (void){
    int nan[9];
    int Nnan[2];
    int res =0;
    for(int i = 0 ; i < 9 ; i++){
        cin>>nan[i];
        res+=nan[i];
    }
    res-=100;
    // cout<<res;
    for (int i = 0; i < 9; i++)
    {
        int temp=0;
        for (int j = 0; j < 9; j++)
        {
            if (nan[i] != nan[j]){
                if (nan[i] + nan[j]== res)
                {
                    Nnan[0] = nan[i];
                    Nnan[1] = nan[j];
                    sort(nan, nan + 10);
                    for (int i = 0; i < 9; i++)
                    {
                        if (nan[i] == Nnan[0] || nan[i] == Nnan[1])
                        {
                            continue;
                        }
                        cout << nan[i] << '\n';
                    }
                    return 0;
                }
            }
        }
    }
}