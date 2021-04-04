#include<iostream>
using namespace std;

int main (void){
    int num;
    cin>>num;
    int dist[num+1];
   
    for(int i = num; i >0  ; i--) dist[i]=num;
    dist[num] = 0;

    for (int i = num-1; i > 0; i--)
    {
        if(i*3<=num)
        {
            int x,y;
            x=min(dist[i],dist[i+1]);
            y=min(dist[i*2],dist[i*3]);
            dist[i]=min(x,y)+1;
            //dist[i]=min({dist[i] , dist[i + 1] , dist[ i * 2  ] , dist[ i * 3]})+1; 버전차이
            
            
            continue;
        }
        if(i*2<=num)
        {
            int x;
            x=min(dist[i],dist[i+1]);
            dist[i]=min(x,dist[i*2])+1;
            //dist[i] = min({dist[i], dist[i + 1], dist[i * 2 ]}) + 1; 버전차이
            continue;
        }
        dist[i] = min(dist[i],dist[i + 1]) + 1;
    }
    cout << dist[1];
}