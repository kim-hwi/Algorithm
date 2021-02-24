
#include <iostream>
#include <fstream>
#include <istream>
#include <string.h>
#include <time.h>


using namespace std;

string board[1311];
string bubbleboard[1311][5];
string bubbleboard2[1311][5];
string selctionboard[1311][5];
string selctionboard2[1311][5];
string shellboard[1311][5];
string shellboard2[1311][5];
string mergeboard[1311][5];
string sortedmergeboard[1311][5];
string mergeboard2[1311][5];
string sortedmergeboard2[1311][5];
string sortedmergeboard3[1311][5];

void bubblesort (string bubbleboard[][5],string ver){
    int i, j;
    string temp[5]; 
    for(i=0; i<1309; i++){ 
        for(j=0; j<1309-i; j++){ 
            if(stoi(bubbleboard[j][2]) > stoi(bubbleboard[j+1][2])&&ver=="year"){ 
                for(int m=0;m<5;m++){
                       std::swap(bubbleboard[j][m], bubbleboard[j+1][m]);
                }            
                
            } 
            if((stoi(bubbleboard[j][4])) > stoi(bubbleboard[j+1][4])&&ver=="ea"){ 
                for(int m=0;m<5;m++){
                       std::swap(bubbleboard[j][m], bubbleboard[j+1][m]);
                }            
                
            }
            if(stoi(bubbleboard[j][2]) == stoi(bubbleboard[j+1][2])&&(stoi(bubbleboard[j][4])) > stoi(bubbleboard[j+1][4])&&ver=="yearandea"){ 
                for(int m=0;m<5;m++){
                       std::swap(bubbleboard[j][m], bubbleboard[j+1][m]);
                }            
                
            }  

        } 
    } 
}





void selctionsort(string selctionboard[][5], string ver){
    for (int startIndex = 0; startIndex < 1310 - 1; ++startIndex) 
    { 
        int smallestIndex = startIndex; 
        for (int currentIndex = startIndex + 1; currentIndex < 1310; ++currentIndex) { 
            if (stoi(selctionboard2[currentIndex][4]) < stoi(selctionboard2[smallestIndex][4])&&ver=="ea") smallestIndex = currentIndex;    
            else if ((selctionboard[currentIndex][2] < selctionboard[smallestIndex][2])&&ver=="year") smallestIndex = currentIndex; 
            
        }  
            
            for(int m=0;m<5;m++){
                std::swap(selctionboard[startIndex][m], selctionboard[smallestIndex][m]);
            } 
    } 
}



void shellsort(string shellboard[][5],string ver){
    int i, j;
    string temp[5];
    int size=1310;
    int gap = size / 2;
    while( gap > 0 ) {
        for( i=gap; i<size; i++ ) {
            for(int p=0;p<5;p++){
                temp[p] = shellboard[i][p];
            }
            j = i;
            while( j>=gap && shellboard[j-gap][2]>temp[2] && ver=="year" ) {
                for(int p=0;p<5;p++){
                    shellboard[j][p] = shellboard[j-gap][p];
                }
                j -= gap;
            }

            while( j>=gap && stoi(shellboard2[j-gap][4])>stoi(temp[4]) && ver=="ea" ) {
                for(int p=0;p<5;p++){
                    shellboard[j][p] = shellboard[j-gap][p];
                }
                j -= gap;
            }

            while( j>=gap && (stoi(shellboard[j-gap][2])==stoi(temp[2]) )&& (stoi(shellboard[j-gap][4])>stoi(temp[4]) ) && ver=="yearandea" ) {
                for(int p=0;p<5;p++){
                    shellboard[j][p] = shellboard[j-gap][p];
                }
                j -= gap;
            }

            for(int p=0;p<5;p++){
                    shellboard[j][p] = temp[p];
                }
        }
        gap /= 2;
    }
}


 
void merge(string mergeboard[][5], string ver, int start, int end)
{
    
    int mid = (start + end) / 2;
    int i = start, j = mid+1, k = start;
    while (i <= mid && j <= end) {
        if (mergeboard[i][2]<= mergeboard[j][2] && ver=="year") {
            for(int p=0;p<5;p++)
                sortedmergeboard[k][p]=mergeboard[i][p];
            k++; i++;
        }

        else if (stoi(mergeboard[i][4]) <= stoi(mergeboard[j][4])&& ver=="ea") {
            for(int p=0;p<5;p++)
                sortedmergeboard[k][p]=mergeboard[i][p];
            k++; i++;
        }

        else if ( (mergeboard[i][2] < mergeboard[j][2]) && ver == "yearandea" ) {
            for(int p=0;p<5;p++)
                sortedmergeboard[k][p]=mergeboard[i][p];
            k++; i++;
        }
        else if ( (mergeboard[i][2] == mergeboard[j][2]) && (stoi(mergeboard[i][4]) < stoi(mergeboard[j][4])) && ver == "yearandea" ) {
            for(int p=0;p<5;p++)
                sortedmergeboard[k][p]=mergeboard[i][p];
            k++; i++;
        }
        else{
            for(int p=0;p<5;p++){
                sortedmergeboard[k][p]=mergeboard[j][p];
            }
            k++; j++;        
        }
    }
 
    while (i <= mid){
        for(int p=0;p<5;p++)
            sortedmergeboard[k][p]=mergeboard[i][p];
        k++; i++;
    }
    while (j <= end){
        for(int p=0;p<5;p++)
            sortedmergeboard[k][p]=mergeboard[j][p];
        k++; j++;
    }

    for (int i = start; i <= end; i++) {
            for(int p=0;p<5;p++){
                mergeboard[i][p]=sortedmergeboard[i][p];
            }
    }
}


void mergesort(string mergeboard[][5],string ver,int start, int end) 
{
    if (start < end) {
        int mid = (start + end) / 2;
        mergesort(mergeboard,ver,start, mid);
        mergesort(mergeboard,ver,mid + 1, end);
        merge(mergeboard,ver,start, end);
    }
}





int main (void)
{
clock_t start_point, end_point;

    fstream st; 
    string str_buf;  
    st.open("Fighters.csv", ios::in | ios::out);
    int line=0;
    int width=0;
    
    while(!st.eof()){
        
        getline(st,str_buf);
        //cout<<str_buf<<" "<<endl;
        board[line]=str_buf;
        
        char *char_buf = new char[100];
        strcpy(char_buf, board[line].c_str());
        char* tok = strtok(char_buf,",");
          while (tok != nullptr) {
            
            bubbleboard[line][width]= string(tok);
            bubbleboard2[line][width]= string(tok);
            selctionboard[line][width]=string(tok);
            selctionboard2[line][width]=string(tok);
            shellboard[line][width]=string(tok);
            shellboard2[line][width]=string(tok);
            mergeboard[line][width]=string(tok);
            mergeboard2[line][width]=string(tok);

            tok = strtok(nullptr, ",");
            width++;
            
          }

        if(width==5){
            width=0;
            line++;
        }
        
    }
    st.close();






 
    start_point = clock();
    bubblesort(bubbleboard,"year"); //버블소트 for year
    end_point = clock();
    bubblesort(bubbleboard,"yearandea"); //버블소트 for year 한 후 year가 같으면 ea로 비교
    
    printf("버블소트    for year -> Exe time : %f sec\n", ((double)(end_point - start_point)/CLOCKS_PER_SEC));
    end_point = clock();
    printf("버블소트    for year 한 후 year가 같으면 ea로 비교 -> Exe time : %f sec\n", ((double)(end_point - start_point)/CLOCKS_PER_SEC));

    // for(int i=0;i<1310 ;i++){
    //       for(int j=0;j<5;j++){
    //           cout<<bubbleboard[i][j]<<" ";
    //       }
    //      cout<<'\n';
    // }
    


    
    start_point = clock();
    selctionsort(selctionboard,"year");  //설렉션소트 for year
    end_point = clock();
    selctionsort(selctionboard,"yearandea"); //설렉션소트 for year 한 후 year가 같으면 ea로 비교
    printf("설렉션소트  for year -> Exe time : %f sec\n", ((double)(end_point - start_point)/CLOCKS_PER_SEC));
    end_point = clock();
    printf("설렉션소트  for year 한 후 year가 같으면 ea로 비교 -> Exe time : %f sec\n", ((double)(end_point - start_point)/CLOCKS_PER_SEC));
    // for(int i=0;i<1310 ;i++){
    //       for(int j=0;j<5;j++){
    //           cout<<selctionboard[i][j]<<' ';
    //       }
    //      cout<<'\n';
    //   }
   
    start_point = clock();
    shellsort(shellboard,"year"); //쉘소트 for year
    end_point = clock();
    printf("쉘소트      for year -> Exe time : %f sec\n", ((double)(end_point - start_point)/CLOCKS_PER_SEC));
    shellsort(shellboard,"yearandea");  //쉘소트 for year 한 후 year가 같으면 ea로 비교
    end_point = clock();
    printf("쉘소트      for year 한 후 year가 같으면 ea로 비교 -> Exe time : %f sec\n", ((double)(end_point - start_point)/CLOCKS_PER_SEC));
    //  for(int i=0;i<1310 ;i++){
    //       for(int j=0;j<5;j++){
    //           cout<<shellboard[i][j]<<" ";
    //       }
    //      cout<<'\n';
    //   }
    
    start_point = clock();
    mergesort(mergeboard,"year",0,1309); //머지소트 for year
    end_point = clock();
    printf("머지소트    for year -> Exe time : %f sec\n", ((double)(end_point - start_point)/CLOCKS_PER_SEC));
    
    start_point = clock();
    mergesort(mergeboard,"yearandea",0,1309);
    // mergesort(mergeboard,"ea",0,1309); //머지소트 for ea
    // mergesort(mergeboard,"year",0,1309); //머지소트 for year
    end_point = clock();
    
    printf("머지소트    for year 한 후 year가 같으면 ea로 비교 -> Exe time : %f sec\n", ((double)(end_point - start_point)/CLOCKS_PER_SEC));
    

     for(int i=0;i<1310 ;i++){
          for(int j=0;j<5;j++){
              cout<<mergeboard[i][j]<<" ";
          }
         cout<<'\n';
      }
    







    start_point = clock();
    bubblesort(bubbleboard2,"ea");
    //bubblesortFORea(); //버블소트 for ea
    end_point = clock();
    printf("버블소트    for ea -> Exe time : %f sec\n", ((double)(end_point - start_point)/CLOCKS_PER_SEC));
    //  for(int i=0;i<1310 ;i++){
    //       for(int j=0;j<5;j++){
    //           cout<<bubbleboard2[i][j]<<" ";
    //       }
    //      cout<<'\n';
    //   }
    

    start_point = clock();
    selctionsort(selctionboard2,"ea");
    end_point = clock();
    printf("설렉션소트  for ea -> Exe time : %f sec\n", ((double)(end_point - start_point)/CLOCKS_PER_SEC));
   
    // for(int i=0;i<1310 ;i++){
    //       for(int j=0;j<5;j++){
    //           cout<<selctionboard2[i][j];
    //       }
    //      cout<<'\n';
    //   }

    start_point = clock();
    shellsort(shellboard2,"ea");//쉘소트 for ea
    end_point = clock();
    printf("쉘소트      for ea -> Exe time : %f sec\n", ((double)(end_point - start_point)/CLOCKS_PER_SEC));


    //  for(int i=0;i<1310 ;i++){
    //       for(int j=0;j<5;j++){
    //           cout<<shellboard2[i][j];
    //       }
    //      cout<<'\n';
    //   }

    start_point = clock();
    mergesort(mergeboard2,"ea",0,1309);//머지소트 for ea
    end_point = clock();
    printf("머지소트    for ea -> Exe time : %f sec\n", ((double)(end_point - start_point)/CLOCKS_PER_SEC));
    
    //  for(int i=0;i<1310 ;i++){
    //       for(int j=0;j<5;j++){
    //           cout<<mergeboard2[i][j]<<" ";
    //       }
    //      cout<<'\n';
    //   }



    return 0;
}