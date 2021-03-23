#include<iostream>
#include<queue>
#include<stack>
#include<utility>
using namespace std;
int main (void){
    int comEA,connet,start;
    cin>>comEA>>connet>>start;
    int board[connet][2];
    bool vis[comEA];
    for(int i = 0 ; i < connet ; i++){
        int x,y;
        cin>>x>>y;
        board[i][0]=min(x,y);
        board[i][1]=max(x,y);
    }

    for(int i = 0 ; i < comEA ; i++) vis[i]=false;

    int i, j;
    int temp2[5];
    int size = connet;
    int gap = size / 2;
    while (gap > 0)
    {
        for (i = gap; i < size; i++)
        {
            for (int p = 0; p < 2; p++)
            {
                temp2[p] = board[i][p];
            }
            j = i;
            while (j >= gap && board[j - gap][0] > temp2[0])
            {
                for (int p = 0; p < 2; p++)
                {
                    board[j][p] = board[j - gap][p];
                }
                j -= gap;
            }
            for (int p = 0; p < 2; p++)
            {
                board[j][p] = temp2[p];
            }
        }
        gap /= 2;
    }
    

    i=0, j=0;
    int temp[5];
    size = connet;
    gap = size / 2;

    
    while (gap > 0)
    {
        for (i = gap; i < size; i++)
        {
            for (int p = 0; p < 2; p++)
            {
                temp[p] = board[i][p];
            }
            j = i;
            while ( (j >= gap )  &&  (board[j - gap][0] == temp[0] )  &&  (board[j - gap][1] > temp[1]))
            {
                for (int p = 0; p < 2; p++)
                {
                    board[j][p] = board[j - gap][p];
                }
                j -= gap;
            }
            for (int p = 0; p < 2; p++)
            {
                board[j][p] = temp[p];
            }
        }
        gap /= 2;
    }
    cout<<endl;
    // for(int i = 0 ; i < connet ; i++){
    //     cout<<board[i][0]<<" "<<board[i][1]<<endl;
    // }
    queue<pair<int,int> > Q;
    vis[start - 1] = true;
    cout<<start<<endl;
    for (int i = 0; i < comEA; i++)
    {
        if (board[i][0] == start || board[i][1] == start){
            if(board[i][0]==0 || board[i][1]==0) continue;
            Q.push(pair<int, int>(board[i][0], board[i][1]));
            if (vis[board[i][0] - 1] == false){
                cout << board[i][0] << endl;
                vis[board[i][0] - 1] = 1;
            }
                
                //cout << board[i][0] << endl;
            if (vis[board[i][1] - 1] == false){
                cout <<board[i][1]<< endl;
                vis[board[i][1] - 1] = 1;
            }
            //cout<<"?"<<endl;      
            //cout << board[i][1] << endl;
        }
    }
    //cout<<endl;
    while(!Q.empty()){
        
        pair<int, int> cur = Q.front();
        Q.pop();
        //cout<<"cur"<<cur.first<<" "<<cur.second<<endl;
        //if (vis[cur.first - 1] == 1 && vis[cur.second - 1] == 1) continue;
        
        // if (vis[cur.first - 1] == false){
        //     cout << cur.first << endl;
        //     vis[board[i][0] - 1] = true;
        // }  
        // if (vis[cur.second - 1] == false){
        //     cout << cur.second << endl;
        //     vis[board[i][1] - 1] = true;
        // }
        
        //cout<<endl;
        for (int i = 0; i < connet; i++)
        {
            //cout << board[i][0] <<" cur.f "<<cur.first<< "  " << board[i][1] <<" cur.s "<<cur.second<< "   " << vis[board[i][0] - 1] << " " << vis[board[i][1]- 1] << endl;
            if (((board[i][0] == cur.first || board[i][0] == cur.second) && (vis[board[i][1] - 1] == false || vis[board[i][0] - 1] == false)) || ((board[i][1] == cur.first || board[i][1] == cur.second) && (vis[board[i][1] - 1] == false || vis[board[i][0] - 1] == false)))
            {
                //cout << "?" << endl;
                Q.push(pair<int, int>(board[i][0], board[i][1]));
                
                if (vis[board[i][0] - 1] == false)
                {
                    cout << board[i][0] << endl;
                    vis[board[i][0] - 1] = true;
                }

                if (vis[board[i][1] - 1] == false)
                {
                    //cout << board[i][0] << " " << board[i][1] << " " << vis[cur.first - 1] << " " << vis[cur.second - 1] << endl;
                    cout << board[i][1] << endl;
                    vis[board[i][1] - 1] = true;
                }
                
                vis[board[i][0] - 1] = true;
                vis[board[i][1] - 1] = true;
            }
        }
        vis[cur.first - 1] = 1;
        vis[cur.second - 1] = 1;
    }
    
}