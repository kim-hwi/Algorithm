#include<iostream>
using namespace std;
int main (void){
    int x,y,stx,sty,nowx,nowy,base,right,left,up,down,top,insnum,temp;
    cin>>x>>y>>stx>>sty>>insnum;
    int board[x][y];
    int ins[insnum];
    int dise[6];
    for ( int i = 0 ; i < 6 ; i ++) dise[i]=0;
    for ( int i = 0 ; i < x ; i++ )
    {
        for ( int j = 0 ; j < y ; j++ )
        {
            cin>>board[i][j];
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    for ( int i = 0 ; i < insnum ; i++) cin>>ins[i];
    dise[5]=board[stx][sty];
    nowx=stx;
    nowy=sty;
    base=5;
    right=2;
    left=3;
    up=1;
    down=4;
    top=0;
    //cout<<0<<" ";
    for ( int i = 0 ; i < insnum ; i++)
    {
       //cout << "!! "<<i<<" "<<ins[i] << " " << endl;
        if(ins[i] == 1)
        {
            
            if (nowy + 1 > y) {
                //cout<<nowy<<" "<<y<<endl;
                continue;
                
            }
            nowy++;

            for(int j = 0 ; j < 6 ; j ++){
                
                if(base == j)
                {
                    temp = base;
                    base = right;
                    right = top;
                    top = left;
                    left = temp;
                    if(board[nowx][nowy]!=0)
                    {
                        dise[base] = board[nowx][nowy];
                        board[nowx][nowy]=0;
                    }
                    else
                    {
                        board[nowx][nowy] = dise[base];
                    }
                    cout<<dise[top]<<" "; 
                    //cout<<top<<endl;
                    break;
                }
            }    
        }

        if (ins[i] == 2)
        {
            //cout<<"nowx "<<nowx<<endl;;
            if (nowy - 1 < 0)
            {
                //cout << " nowy - 1 < 0 " << nowy << endl;
                continue;

            }
            nowy--;
            for (int j = 0; j < 6; j++)
            {
                if (base == j)
                {
                    temp = base;
                    base = left;
                    left = top;
                    top = right;
                    right = temp;
                    if (board[nowx][nowy] != 0)
                    {
                        dise[base] = board[nowx][nowy];
                        board[nowx][nowy] = 0;
                    }
                    else
                    {
                        board[nowx][nowy] = dise[base];
                    }
                    cout << dise[top] << " ";
                    break;
                }
            }
        }

        if (ins[i] == 3)
        {
            if (nowx - 1 < 0)
            {
                //cout << " nowx - 1 < 0 " << nowx << endl;
                continue;
            }
            nowx--;
            for (int j = 0; j < 6; j++)
            {
                if (base == j)
                {
                    temp = base;
                    base = up;
                    up = top;
                    top = down;
                    down = temp;
                    if (board[nowx][nowy] != 0)
                    {
                        dise[base] = board[nowx][nowy];
                        board[nowx][nowy] = 0;
                    }
                    else
                    {
                        board[nowx][nowy] = dise[base];
                    }
                    cout << dise[top] << " ";
                    break;
                }
            }
        }

        if (ins[i] == 4)
        {
            //cout<<"base"<<base;
            if (nowx + 1 > x)
            {
                //cout << " nowx + 1 > x " << nowx << " " <<x << endl;
                continue;
            }
            nowx++;
            for (int j = 0; j < 6; j++)
            {
                if (base == j)
                {
                    temp = base;
                    base = down;
                    down = top;
                    top = up;
                    up = temp;
                    if (board[nowx][nowy] != 0)
                    {
                        dise[base] = board[nowx][nowy];
                        //cout << " base " << dise[base] << " nowx " << nowx << " nowy " << nowy << " board[][] " << board[nowx][nowy]<<endl; 
                        board[nowx][nowy] = 0;
                    }
                    else
                    {
                        board[nowx][nowy] = dise[base];
                    }
                    cout << dise[top] << " ";
                    //cout << "res "<<dise[top] << " base " << dise[base] <<" down "<< dise[down]<<" up "<<dise[up]<<endl;

                    break;
                }
            }
        }

        

            // if (base == 5){
            //     base = 2;
                


                // if (board[nowx + 1][nowy] != 0)
                // {
                //     dise[base] = board[nowx + 1][nowy];
                //     board[nowx + 1][nowy] = 0;
                // }
                
                // else
                // {
                //     board[nowx + 1][nowy] = dise[base];
                    //cout << dise[5 - base] << endl;
                //}
            //}

            // else if (base == 4)
            // {
            //     base = 2;
            //     if (board[nowx + 1][nowy] != 0)
            //     {
            //         dise[base] = board[nowx + 1][nowy];
            //         board[nowx + 1][nowy] = 0;
            //         //cout << dise[5 - base] << endl;
            //         cout << 5 - base << " " << dise[5 - base] << endl;
            //     }

            //     else
            //     {
            //         board[nowx + 1][nowy] = dise[base];
            //         //cout << dise[5 - base] << endl;
            //         cout << 5 - base << " " << dise[5 - base] << endl;
            //     }
            // }

            // else if (base == 3)
            // {
            //     base = 0;
            //     if (board[nowx + 1][nowy] != 0)
            //     {
            //         dise[base] = board[nowx + 1][nowy];
            //         board[nowx + 1][nowy] = 0;
            //         //cout << dise[5 - base] << endl;
            //         cout << 5 - base << " " << dise[5 - base] << endl;
            //     }

            //     else
            //     {
            //         board[nowx + 1][nowy] = dise[base];
            //         //cout << dise[5 - base] << endl;
            //         cout << 5 - base << " " << dise[5 - base] << endl;
            //     }
            // }

            // else if (base == 2)
            // {
            //     base = 5;
            //     if (board[nowx + 1][nowy] != 0)
            //     {
            //         dise[base] = board[nowx + 1][nowy];
            //         board[nowx + 1][nowy] = 0;
            //         //cout << dise[5 - base] << endl;
            //         cout << 5 - base << " " << dise[5 - base] << endl;
            //     }

            //     else
            //     {
            //         board[nowx + 1][nowy] = dise[base];
            //         //cout << dise[5 - base] << endl;
            //         cout << 5 - base << " " << dise[5 - base] << endl;
            //     }
            // }

            // else if (base == 1)
            // {
            //     base = 2;
            //     if (board[nowx + 1][nowy] != 0)
            //     {
            //         dise[base] = board[nowx + 1][nowy];
            //         board[nowx + 1][nowy] = 0;
            //         //cout << dise[5 - base] << endl;
            //         cout << 5 - base << " " << dise[5 - base] << endl;
            //     }

            //     else
            //     {
            //         board[nowx + 1][nowy] = dise[base];
            //         //cout << dise[5 - base] << endl;
            //         cout << 5 - base << " " << dise[5 - base] << endl;
            //     }
            // }

            // else if (base == 0)
            // {
            //     base = 2;
            //     if (board[nowx + 1][nowy] != 0)
            //     {
            //         dise[base] = board[nowx + 1][nowy];
            //         board[nowx + 1][nowy] = 0;
            //         //cout << dise[5 - base] << endl;
            //         cout << 5 - base << " " << dise[5 - base] << endl;
            //     }

            //     else
            //     {
            //         board[nowx + 1][nowy] = dise[base];
            //         //cout << dise[5 - base] << endl;
            //         cout << 5 - base << " " << dise[5 - base] << endl;
            //     }
            // }

        //}
        // if (ins[i] == 2)
        // {
        //     if (nowy - 1 < 0)
        //         continue;
        // }
        // if (ins[i] == 3)
        // {
        //     if (nowy - 1 < 0)
        //         continue;
        // }
        // if (ins[i] == 4)
        // {
        //     if (nowy + 1 >= y)
        //         continue;
        // }

    }
}
