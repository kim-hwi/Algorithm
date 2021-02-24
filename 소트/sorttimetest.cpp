
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

void bubblesortFORyear (string bubbleboard[][5]){
    int i, j;
    string temp[5]; 
    for(i=0; i<1309; i++){ 
        for(j=0; j<1309-i; j++){ 
            if(stoi(bubbleboard[j][2]) > stoi(bubbleboard[j+1][2])){ 
                for(int m=0;m<5;m++){
                       std::swap(bubbleboard[j][m], bubbleboard[j+1][m]);
                }            
                
            } 
        } 
    } 
}
void bubblesortFORea (){
    int i, j;
    string temp[5]; 
    for(i=0; i<1309; i++){ 
        for(j=0; j<1309-i; j++){ 
            if((stoi(bubbleboard2[j][4])) > stoi(bubbleboard2[j+1][4])){ 
                for(int m=0;m<5;m++){
                       std::swap(bubbleboard2[j][m], bubbleboard2[j+1][m]);
                }            
                
            } 
        } 
    } 
}

void bubblesortFORyearANDea (){
    int i, j;
    string temp[5]; 
    for(i=0; i<1309; i++){ 
        for(j=0; j<1309-i; j++){ 
            if(stoi(bubbleboard[j][2]) == stoi(bubbleboard[j+1][2])&&(stoi(bubbleboard[j][4])) > stoi(bubbleboard[j+1][4])){ 
                for(int m=0;m<5;m++){
                       std::swap(bubbleboard[j][m], bubbleboard[j+1][m]);
                }            
                
            } 
        } 
    } 
}

void selctionsortFORyear(){
    for (int startIndex = 0; startIndex < 1310 - 1; ++startIndex) 
    { 
        int smallestIndex = startIndex; 
        for (int currentIndex = startIndex + 1; currentIndex < 1310; ++currentIndex) { 
            if (selctionboard[currentIndex][2] < selctionboard[smallestIndex][2]) smallestIndex = currentIndex; }  
            for(int m=0;m<5;m++){
                std::swap(selctionboard[startIndex][m], selctionboard[smallestIndex][m]);
            } 
    } 
}

void selctionsortFORea(){
    for (int startIndex = 0; startIndex < 1310 - 1; ++startIndex) 
    { 
        int smallestIndex = startIndex; 
        for (int currentIndex = startIndex + 1; currentIndex < 1310; ++currentIndex) { 
            if (stoi(selctionboard2[currentIndex][4]) < stoi(selctionboard2[smallestIndex][4])) smallestIndex = currentIndex; }  
            for(int m=0;m<5;m++){
                std::swap(selctionboard2[startIndex][m], selctionboard2[smallestIndex][m]);
            } 
    } 
}

void selctionsortFORyearANDea(){
    for (int startIndex = 0; startIndex < 1310 - 1; ++startIndex) 
    { 
        int smallestIndex = startIndex; 
        for (int currentIndex = startIndex + 1; currentIndex < 1310; ++currentIndex) { 
            if ((selctionboard[currentIndex][2] == selctionboard[smallestIndex][2])&&(selctionboard[currentIndex][4] < selctionboard[smallestIndex][4])) smallestIndex = currentIndex; }  
            for(int m=0;m<5;m++){
                std::swap(selctionboard[startIndex][m], selctionboard[smallestIndex][m]);
            } 
    } 
}

void shellsortFORyear(){
    int i, j;
    string temp2[5];
    int size=1310;
    int gap = size / 2;
    while( gap > 0 ) {
        for( i=gap; i<size; i++ ) {
            for(int p=0;p<5;p++){
                temp2[p] = shellboard[i][p];
            }
            j = i;
            while( j>=gap && shellboard[j-gap][2]>temp2[2] ) {
                for(int p=0;p<5;p++){
                    shellboard[j][p] = shellboard[j-gap][p];
                }
                j -= gap;
            }
            for(int p=0;p<5;p++){
                    shellboard[j][p] = temp2[p];
                }
        }
        gap /= 2;
    }
}

void shellsortFORea(){
    int i, j;
    string temp[5];
    int size=1310;
    int gap = size / 2;
    while( gap > 0 ) {
        for( i=gap; i<size; i++ ) {
            for(int p=0;p<5;p++){
                temp[p] = shellboard2[i][p];
            }
            j = i;
            while( j>=gap && stoi(shellboard2[j-gap][4])>stoi(temp[4]) ) {
                for(int p=0;p<5;p++){
                    shellboard2[j][p] = shellboard2[j-gap][p];
                }
                j -= gap;
            }
            for(int p=0;p<5;p++){
                    shellboard2[j][p] = temp[p];
                }
        }
        gap /= 2;
    }
}

void shellsortFORyearANDea(){
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
            while( j>=gap && stoi(shellboard[j-gap][2])==stoi(temp[2]) && stoi(shellboard[j-gap][4])>stoi(temp[4])  ) {
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


 
void mergeFORyear(int start, int end)
{
    
    int mid = (start + end) / 2;
    int i = start, j = mid+1, k = start;
    while (i <= mid && j <= end) {
        if (mergeboard[i][2]<= mergeboard[j][2]) {
            for(int p=0;p<5;p++){
                sortedmergeboard[k][p]=mergeboard[i][p];
            }
            k++;
            i++;
        }
            
        else{
            for(int p=0;p<5;p++){
                sortedmergeboard[k][p]=mergeboard[j][p];
            }
            k++;
            j++;        
        }
    }
 
    while (i <= mid){
        for(int p=0;p<5;p++){
            sortedmergeboard[k][p]=mergeboard[i][p];
        }
        k++;
        i++;
    }
    while (j <= end){
        for(int p=0;p<5;p++){
            sortedmergeboard[k][p]=mergeboard[j][p];
        }
        k++;
        j++;
    }
    for (int i = start; i <= end; i++) {
        for(int p=0;p<5;p++){
            mergeboard[i][p]=sortedmergeboard[i][p];
        }
    }
    
}

void mergeFORea(int start, int end)
{
    
    int mid = (start + end) / 2;
    int i = start, j = mid+1, k = start;
    while (i <= mid && j <= end) {
        if (stoi(mergeboard2[i][4]) <= stoi(mergeboard2[j][4])) {
            for(int p=0;p<5;p++){
                sortedmergeboard2[k][p]=mergeboard2[i][p];
            }
            k++;
            i++;
        }
            
        else{
            for(int p=0;p<5;p++){
                sortedmergeboard2[k][p]=mergeboard2[j][p];
            }
            k++;
            j++;        
        }
    }
 
    while (i <= mid){
        for(int p=0;p<5;p++){
            sortedmergeboard2[k][p]=mergeboard2[i][p];
        }
        k++;
        i++;
    }
    while (j <= end){
        for(int p=0;p<5;p++){
            sortedmergeboard2[k][p]=mergeboard2[j][p];
        }
        k++;
        j++;
    }
    for (int i = start; i <= end; i++) {
        for(int p=0;p<5;p++){
            mergeboard2[i][p]=sortedmergeboard2[i][p];
        }
    }
    
}

void mergeFORyearANDea(int start, int end)
{
    
    int mid = (start + end) / 2;
    int i = start, j = mid+1, k = start;
    while (i <= mid && j <= end) {
        if ((mergeboard[i][2] == mergeboard[j][2])&&(stoi(mergeboard2[i][4]) <= stoi(mergeboard2[j][4]))) {
            for(int p=0;p<5;p++){
                sortedmergeboard[k][p]=mergeboard[i][p];
            }
            k++;
            i++;
        }
            
        else{
            for(int p=0;p<5;p++){
                sortedmergeboard[k][p]=mergeboard[j][p];
            }
            k++;
            j++;        
        }
    }
 
    while (i <= mid){
        for(int p=0;p<5;p++){
            sortedmergeboard[k][p]=mergeboard[i][p];
        }
        k++;
        i++;
    }
    while (j <= end){
        for(int p=0;p<5;p++){
            sortedmergeboard[k][p]=mergeboard[j][p];
        }
        k++;
        j++;
    }
    for (int i = end; i <= start; i--) {
        for(int p=0;p<5;p++){
            mergeboard[i][p]=sortedmergeboard[i][p];
        }
    }
    
}
 
void mergesortFORyear(int start, int end) 
{
    if (start < end) {
        int mid = (start + end) / 2;
        mergesortFORyear(start, mid);
        mergesortFORyear(mid + 1, end);
        mergeFORyear(start, end);
    }
}

void mergesortFORea(int start, int end) 
{
    if (start < end) {
        int mid = (start + end) / 2;
        mergesortFORea(start, mid);
        mergesortFORea(mid + 1, end);
        mergeFORea(start, end);
    }
}

void mergesortFORyearANDea(int start, int end) 
{
    if (start < end) {
        int mid = (start + end) / 2;
        mergesortFORyearANDea(start, mid);
        mergesortFORyearANDea(mid + 1, end);
        mergeFORyearANDea(start, end);
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
        board[line]=str_buf;
        
        char *char_buf = new char[100];
        strcpy(char_buf, board[line].c_str());
        char* tok = strtok(char_buf,",");
          while (tok != nullptr) {
            
            

            tok = strtok(nullptr, ",");
            width++;
            
          }
    }cout<<line;
        line=0;
        width=0;

    while(!st.eof()){
        
        getline(st,str_buf);
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
    bubblesortFORyear(bubbleboard); //버블소트 for year
    end_point = clock();
    bubblesortFORyearANDea ();  //버블소트 for year 한 후 year가 같으면 ea로 비교
    printf("버블소트    for year -> Exe time : %f sec\n", ((double)(end_point - start_point)/CLOCKS_PER_SEC));
    end_point = clock();
    printf("버블소트    for year 한 후 year가 같으면 ea로 비교 -> Exe time : %f sec\n", ((double)(end_point - start_point)/CLOCKS_PER_SEC));

    // for(int i=0;i<1310 ;i++){
    //       for(int j=0;j<5;j++){
    //           cout<<bubbleboard[i][j];
    //       }
    //      cout<<'\n';
    // }
    


    
    start_point = clock();
    selctionsortFORyear();  //설렉션소트 for year
    end_point = clock();
    selctionsortFORyearANDea(); //설렉션소트 for year 한 후 year가 같으면 ea로 비교
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
    shellsortFORyear(); //쉘소트 for year
    end_point = clock();
    printf("쉘소트      for year -> Exe time : %f sec\n", ((double)(end_point - start_point)/CLOCKS_PER_SEC));
    selctionsortFORyearANDea(); //쉘소트 for year 한 후 year가 같으면 ea로 비교
    end_point = clock();
    printf("쉘소트      for year 한 후 year가 같으면 ea로 비교 -> Exe time : %f sec\n", ((double)(end_point - start_point)/CLOCKS_PER_SEC));
    //  for(int i=0;i<1310 ;i++){
    //       for(int j=0;j<5;j++){
    //           cout<<shellboard[i][j];
    //       }
    //      cout<<'\n';
    //   }
    

    start_point = clock();
    mergesortFORyear(0,1309); //머지소트 for year
    end_point = clock();
    printf("머지소트    for year -> Exe time : %f sec\n", ((double)(end_point - start_point)/CLOCKS_PER_SEC));
    mergesortFORyearANDea(0,1309);//머지소트 for year 한 후 year가 같으면 ea로 비교
    end_point = clock();
    printf("머지소트    for year 한 후 year가 같으면 ea로 비교 -> Exe time : %f sec\n", ((double)(end_point - start_point)/CLOCKS_PER_SEC));
     for(int i=0;i<1310 ;i++){
          for(int j=0;j<5;j++){
              cout<<mergeboard[i][j]<<" ";
          }
         cout<<'\n';
      }
    


    start_point = clock();
    bubblesortFORea(); //버블소트 for ea
    end_point = clock();
    printf("버블소트    for ea -> Exe time : %f sec\n", ((double)(end_point - start_point)/CLOCKS_PER_SEC));
    //  for(int i=0;i<1310 ;i++){
    //       for(int j=0;j<5;j++){
    //           cout<<bubbleboard2[i][j]<<" ";
    //       }
    //      cout<<'\n';
    //   }
    

    start_point = clock();
    selctionsortFORea();
    end_point = clock();
    printf("설렉션소트  for ea -> Exe time : %f sec\n", ((double)(end_point - start_point)/CLOCKS_PER_SEC));
   
    // for(int i=0;i<1310 ;i++){
    //       for(int j=0;j<5;j++){
    //           cout<<selctionboard[i][j];
    //       }
    //      cout<<'\n';
    //   }

    start_point = clock();
    shellsortFORea();//쉘소트 for ea
    end_point = clock();
    printf("쉘소트      for ea -> Exe time : %f sec\n", ((double)(end_point - start_point)/CLOCKS_PER_SEC));


    //  for(int i=0;i<1310 ;i++){
    //       for(int j=0;j<5;j++){
    //           cout<<shellboard2[i][j];
    //       }
    //      cout<<'\n';
    //   }

    start_point = clock();
    mergesortFORea(0,1309);//머지소트 for ea
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