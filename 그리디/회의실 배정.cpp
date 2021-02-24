#include<iostream>
using namespace std;
int main (void){
    int num,start,end,count=1;
    cin>>num;
    double time[num][2];
    for(int i=0;i<num;i++)  cin>>time[i][0]>>time[i][1];

    //시간복잡도 때문에 상대적 짧은 쉘소트 사용
    int i=0, j=0;
    int temp2[2];
    int gap = num / 2;
    while( gap > 0 ) {
        for( i=gap; i<num; i++ ) {
            for(int p=0;p<2;p++){
                temp2[p] = time[i][p];
            }
            j = i;
            while( j>=gap && time[j-gap][1]>temp2[1] ) {
                for(int p=0;p<2;p++){
                    time[j][p] = time[j-gap][p];
                }
                j -= gap;
            }
            /*4 8  2 8  8 8 이런식의 경우 end time이 같지만 8 8이 실행되기 때문에 답은 2가 나와야 하지만
            8 8을 인식하지 못해 뒤가 같을땐 앞을 소트해주어야함.*/ 
            while(j>=gap && time[j-gap][1]==temp2[1] && time[j-gap][0]>temp2[0] ) {
                for(int p=0;p<2;p++){
                    time[j][p] = time[j-gap][p];
                }
                j -= gap;
            }

            for(int p=0;p<2;p++){
                    time[j][p] = temp2[p];
                }
        
        }
        gap /= 2;
    }



    start=time[0][0];
    end=time[0][1];
    //cout<<endl<<"start= "<<start<<" end= "<<end<<" count= "<<count;
    for(int i=0;i<num;i++){
        if(time[i][0]>=end&i!=0){
            //start!=time[i][0]&end!=time[i][1]
            start=time[i][0];
            end=time[i][1];
            count++;
            //cout<<endl<<"start= "<<start<<" end= "<<end<<" count= "<<count<<" i= "<<i<<endl;
        }
    }
    // for(int i=0;i<num;i++){
    //     cout<<endl<<time[i][0]<<" "<<time[i][1];
    // }

    cout<<count;
}
