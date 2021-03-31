#include<iostream>
#include<algorithm>
using namespace std;
int main (void){
    int day,x,y;
    cin>>day;
    int daydata[day][3];
    bool ch[day];
    //cout<<endl;
    for( int i = 0 ; i < day ; i++){
        
        cin >> x >> daydata[i][2];
        daydata[i][0] = i + 1;
        daydata[i][1] = x + i;
        //cout << daydata[i][0] <<" "<< daydata[i][1]<<" "<<daydata[i][2]<<endl;
    }
    //cout<<endl;

    int i, j;
    int temp[2];
    int size = day;
    int gap = size / 2;
    while (gap > 0)
    {
        for (i = gap; i < size; i++)
        {
            for (int p = 0; p < 3; p++)
            {
                temp[p] = daydata[i][p];
            }
            j = i;
            while (j >= gap && daydata[j - gap][1] > temp[1])
            {
                for (int p = 0; p < 3; p++)
                {
                    daydata[j][p] = daydata[j - gap][p];
                }
                j -= gap;
            }
            for (int p = 0; p < 3; p++)
            {
                daydata[j][p] = temp[p];
            }
        }
        gap /= 2;
    }
    // cout<<"sort"<<endl;
    // for (int i = 0; i < day; i++)
    // {

    //     //cin >> x >> daydata[i][1];
    //     //daydata[i][0] = x + i - 1;
    //     cout << daydata[i][0] << " " << daydata[i][1] << " " << daydata[i][2] << endl;
    // }

    int newnum=day;
    for(int i = 0 ; i < day ; i++){
        if(daydata[i][1]>day){
            newnum = i;
            break;
        }
    }
    int resdata[newnum][3];
    // cout<<"newdata"<<endl;
    // for (int i = 0; i < newnum; i++)
    // {

    //     //cin >> x >> daydata[i][1];
    //     //daydata[i][0] = x + i - 1;
    //     cout << daydata[i][0] << " " << daydata[i][1] << " " << daydata[i][2] << endl;
    // }

    int top = 0;
    resdata[0][0] = daydata[0][0];
    resdata[0][1] = daydata[0][1];
    resdata[0][2] = daydata[0][2];
    int max = resdata[0][2];
    //cout<<"newnum "<<newnum<<endl;
    for(int i = 1 ; i < newnum ; i++)
    {
        //cout << "resdata[top][2] " << resdata[top][2] << "daydata[i][2] " << daydata[i][2] << endl;
        // if(resdata[top][2] < daydata[i][2])
        // {
            
            if(resdata[top][1] < daydata[i][0])
            {
                top++;
                resdata[top][0] = daydata[i][0];
                resdata[top][1] = daydata[i][1];
                resdata[top][2] = daydata[i][2];
                max+=resdata[top][2];
                //cout<<"max "<<max<<endl;
            }
            else
            {   
                int tempmax=max;
                int point=0;
                for(int j = 0 ; j <= top ; j++ ){
                    if(resdata[top-j][1] >= daydata[i][0]){
                        tempmax -= resdata[top - j][2];
                        point = top - j;
                    }
                }
                tempmax+=daydata[i][2];
                if(tempmax>max){
                    for(int k = newnum-1 ; k >= point ; k--){
                        resdata[k][0]=0;
                        resdata[k][1]=0;
                        resdata[k][2]=0;
                    }
                    resdata[point][0] = daydata[i][0];
                    resdata[point][1] = daydata[i][1];
                    resdata[point][2] = daydata[i][2];
                    max=tempmax;
                    //cout<<"max "<<max;
                }
                // resdata[top][0] = daydata[i][0];
                // resdata[top][1] = daydata[i][1];
                // resdata[top][2] = daydata[i][2];
                // max;
            }
        // }
        // else
        // {

        // }

    }
    // int daydata2[newnum][3];
    // for (int i = 0; i < newnum; i++)
    // {
    //     daydata2[i][0] = daydata[i][0];
    //     daydata2[i][1] = daydata[i][1];
    //     daydata2[i][2] = daydata[i][2];
    // }
    cout<<max<<endl;
    // for (int i = 0 ; i <= top; i++)
    // {
    //     cout << resdata[i][0] <<" "<< resdata[i][1]<<" "<<resdata[i][2]<<endl;
    // }
}

