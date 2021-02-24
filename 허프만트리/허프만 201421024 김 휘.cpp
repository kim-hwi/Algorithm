#include <queue>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

string treesequence="";
map<char,string> char_to_huff;
vector<int> ASCII(128);
string huff_code="";
struct node {
    node* left=nullptr;
    node* right=nullptr;
    char idnum;
    int freq;
};

struct compare{//커스텀
        bool operator()(node& A,node& B){
                return A.freq>B.freq;
        }
};

string towscomplement(string num){//구현실패
    string rel;
    int a[8]={0,},b1[8]={0,},b2[8]={0,};
	int i=-1, c=1; 
    
    for(int q=0;q<8;q++){
        cout<<endl<<a[q]<<" "<<num<<endl;
    }

    
    for(int q=0;q<8;q++){
	cout<<endl<<a[q]<<" "<<num<<endl;
    }
	do{
		i++;
		b1[i] = 1 - a[i];
	}while(i<8);
	
	do{
		b2[i] = b1[i] + c;
		b2[i] = b2[i] % 2;
		c = b1[i] * c;
		i--;
	}while(i>=0);
	
    return 0;
}

string tentotwo(int num){
    int result=0;
    for(int i=1; num>0; i*=10){
        int binary = num % 2;
        result += binary*i;
        num /=2;
    }
    return to_string(result);
}

int towtoten(string str){
        int num;
        int result=0, mul=1;
        std::string int_val = str;
        num = std::stoi(int_val);
        while(num>0){
                if(num%2) result +=mul;
                mul *=2;
                num/=10;
        }
        return result;
};

void frequency(){
    //string in_line;
    ifstream in("test.txt");
    string str;
    char c;
    char carr[9];
    int i=0;
    int a;
    while(in.get(c))
    {
        carr[i++]=c;
        if(i==8){
            str=carr;
            ASCII[towtoten(str)]++;
            i=0;
        }
    }
}

void dfs(node* target,queue<node>& tree){
    cout<<"id num: "<<target->idnum<<endl;
    if (target->idnum == '$')
        treesequence+= "11";
    else
        treesequence+=bitset<8>(target->idnum).to_string();

    if(target->left==nullptr && target->right==nullptr){
        char_to_huff[target->idnum]=huff_code;
        treesequence+= "101";
        return;
    }
    huff_code+="0";
    dfs(target->left,tree);
    huff_code.pop_back();
    huff_code+="1";
    dfs(target->right,tree);
    huff_code.pop_back();
    
    return;
}


int incoder(){
    char c;
    int a;
    int k=0;
    priority_queue<node,vector<node>,compare> pq;
    queue<node> tree,temp;
    vector<node> ref;
    
    string in_line;
    ifstream in("test.txt"); // 폴더의 "test.txt" 파일을 읽어옴

    string asciicode="";
    while(in.get(c))// "test.txt"에서 읽은 파일을 c에 대입하며 더이상 문자가 없을 때 까지 반복
    {  
        asciicode+=c;
        ASCII[c]++;
    }
    
    int numm=0;
    node tt;
    for(const auto &a:ASCII){
        if(a>=1){
            char ch(numm);
            tt.freq = a; tt.idnum=char(static_cast<int>(ch));
            ref.push_back(tt);
        }
        numm++;
    }
    for(const auto &node_info:ref){
        tree.push(node_info);
        pq.push(node_info);
    }
    while(pq.size()>1){
            node leftnode,rightnode,parent;
            
            parent.idnum='$';
            tree.push(parent);
            
            leftnode=pq.top();
            temp.push(leftnode);
            
            tree.back().left=&temp.back();
            pq.pop();
            
            rightnode=pq.top();
            temp.push(rightnode);
            
            tree.back().right=&temp.back();
            pq.pop();

            tree.back().freq=(tree.back().left->freq)+(tree.back().right->freq);
            pq.push(tree.back());
        
    }

    dfs(&tree.back(),tree);

    for(auto iter=char_to_huff.begin();iter!=char_to_huff.end();iter++){
        cout<<iter->first<<": "<<iter->second<<endl;
    }

    string encode_code="";
    for(const auto &c:asciicode){
        encode_code+=(char_to_huff[c]);
    }
    
    ofstream output("data.bin", ios::out | ios::binary);
    string codesize=tentotwo(encode_code.size());


    for (int i = 0;i<treesequence.size();i+=8)
        output << (unsigned char)bitset<8>(treesequence.substr(i,8)).to_ulong();   //허프만 트리를 output파일에 넣음.
    
    int fullsize=encode_code.size();
    string data = bitset<8>(fullsize).to_string();
    cout<< endl <<"codesize for binary :" <<data << endl;
    for (int i = 0;i<data.size();i+=8)
        output << (unsigned char)bitset<8>(data.substr(i,8)).to_ulong(); //허프만 코드로 압축된 코드의 길이가 어디까지 인지(8bit단위로 끊기기 때문에 개수가 8로 나누어떨어 지지 않으면 0으로 채워지기 때문) 파일 맨앞 2byte를 이용하여 표현하여 output파일에 넣음.
    
    
    cout<< "data_encoded :" << encode_code << endl;
    while(encode_code.size() % 8) encode_code += '0';
    for(int i=0; i<encode_code.size(); i+=8)
        output << (unsigned char)bitset<8>(encode_code.substr(i,8)).to_ulong();

    output.close();
    return 1;
}

node* readtree(string& data, int pivot){
    char c;
    bool leaf;
    node* root;

    if (data.substr(pivot, 1) == "0"){
        c = static_cast<char>(bitset<8>(data.substr(pivot, 8)).to_ulong());
        leaf = true;
        pivot += 8;
    }
    else if (data.substr(pivot, 3) == "101"){
        pivot += 3;
        return nullptr;
    }
    else if (data.substr(pivot, 2) == "11"){
        leaf = false;
        pivot += 2;
    }
    cout << "c: " << c<<endl;
    if (leaf){
        node* new_node;
        (*new_node).freq = 1;
        root = new_node;
    }
    else {
        node* new_node;
        (*new_node).freq = 0;
        (*new_node).idnum = c;
        root = new_node;
    }
    root->left = readtree(data, pivot);
    if (root->left == nullptr)
        root->right = nullptr;
        return root;
    root->right = readtree(data, pivot);
    return root;
}

int decoder(){//구현실패
    string data;
    char c;
    int codesize;
    int pivot = 0;
    node* root;

    ifstream input("data.bin", ios::binary);
    while(input.get(c)){
        bitset<8> temp(c);
        data += temp.to_string();
    }
    cout<<"data: " << data<<endl;
    root = readtree(data, pivot);
    cout<<"pivot"<<pivot<<endl;
    codesize = bitset<8>(data.substr(pivot, 8)).to_ulong();
    pivot += 8;

    cout<<"codesize: "<<codesize<<endl;
    return 1;
}



int main(){
    incoder();
    decoder();
    return 0;
}