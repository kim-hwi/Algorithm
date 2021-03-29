#include<iostream>
using namespace std;
int main (void){
    int x,y,stx,sty,nowx,nowy,base,right,left,up,down,top,insnum,temp;
    cin>>x>>y>>stx>>sty>>insnum;//입력을 받는다. x는 상하, y는 좌우 에 유의할것. 
    int board[x][y];
    int ins[insnum];
    int dise[6];
    for ( int i = 0 ; i < 6 ; i ++) dise[i]=0;
    for ( int i = 0 ; i < x ; i++ )
    {
        for ( int j = 0 ; j < y ; j++ )
        {
            cin>>board[i][j];
        }
    }
    for ( int i = 0 ; i < insnum ; i++) cin>>ins[i];
    dise[5]=board[stx][sty];//주사위 생성
    nowx=stx;//증가시킬 보드위의 인덱스
    nowy=sty;
    base=5;//초기상태의 주사위 값 설정
    right=2;
    left=3;
    up=1;
    down=4;
    top=0;
    for ( int i = 0 ; i < insnum ; i++)//명령어 개수만큼 반복
    {
        if(ins[i] == 1)//명령어가 1 => 오른쪽으로 굴릴 때
        {
            if (nowy + 1 == y) {//한계값을 넘어갈때
                continue;
            }
            nowy++;

            for(int j = 0 ; j < 6 ; j ++){//현재의 주사위 상태 체크, 한번만 발동되면 break로 정지할 것
                
                if(base == j)
                {
                    temp = base;//주사위가 굴러가며 값이 바뀜.
                    base = right;
                    right = top;
                    top = left;
                    left = temp;
                    if(board[nowx][nowy]!=0)//문제의 조건문
                    {
                        dise[base] = board[nowx][nowy];
                        board[nowx][nowy]=0;
                    }
                    else//문제의 조건문
                    {
                        board[nowx][nowy] = dise[base];
                    }
                    cout<<dise[top]<<endl; 
                    break;
                }
            }    
        }

        if (ins[i] == 2)
        {
            if (nowy - 1 < 0)
            {
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
                    cout << dise[top] <<endl;
                    break;
                }
            }
        }

        if (ins[i] == 3)
        {
            if (nowx - 1 < 0)
            {
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
                    cout << dise[top] <<endl;
                    break;
                }
            }
        }

        if (ins[i] == 4)
        {
            if (nowx + 1 == x)
            {
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
                        board[nowx][nowy] = 0;
                    }
                    else
                    {
                        board[nowx][nowy] = dise[base];
                    }
                    cout << dise[top] <<endl;
                    break;
                }
            }
        }
    }
}
