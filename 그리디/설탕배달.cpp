#include<iostream>
using namespace std;
int main (void){
    int suger,limit,ea=0;
    cin>>suger;
    limit=suger;
    if (suger == 1 || suger == 2 || suger == 4)//쉬운 계산을 위해 초반부에 if문을 생성
    {
        cout << -1;
        return 0;
    }
    while( suger > 0)//5를 계속해서 빼줌.
    {
        suger -= 5;
        ea++;
    }
    if(suger==0){
        cout<<ea;
        return 0;
    }
    while (1)//복잡하진 않지만 백트래킹의 개념
    {
        suger += 5;
        ea--;
        if (suger > limit)//원래 수를 넘어가면 나눌수 없는 수
        {
            cout << -1;
            return 0;
        }

        if(suger%3==0){//5를 더한수를 3으로 나눌 수 있는지 판단, 나눌 수 있다면 최소의 수
            ea+=suger/3;
            cout<<ea;
            return 0;
        }
        
    }
}