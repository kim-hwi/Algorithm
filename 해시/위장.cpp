#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes)
{
    int answer = 1;
    map<string, int> arr;
    for (int i = 0; i < clothes.size(); i++)
    {
        if (arr.find(clothes[i][1]) == arr.end())
        {
            arr.insert(pair<string, int>(clothes[i][1], 1));
        }
        else
        {
            arr.find(clothes[i][1])->second += 1;
        }
    }
    for (auto it = arr.begin(); it != arr.end(); it++)
    {
        answer *= (it->second + 1);
        cout<<it->second;
    }
    
    return answer - 1;
}