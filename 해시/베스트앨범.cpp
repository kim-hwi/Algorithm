#include <string>
#include <vector>
#include <map>
#include <iostream>

#include <algorithm>
using namespace std;

bool cmp(const pair<string, vector<int>> &a, const pair<string, vector<int>> &b)
{
    if (a.second[0] == b.second[0])
        return a.first > b.first;
    return a.second[0] > b.second[0];
}
vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;
    map<string, vector<int>> arr;
    for (int i = 0; i < genres.size(); i++)
    {
        if (arr.find(genres[i]) == arr.end())
        {
            vector<int> temp;
            temp.push_back(plays[i]);
            temp.push_back(plays[i]);
            temp.push_back(i);
            temp.push_back(-1);
            temp.push_back(-1);
            arr.insert(pair<string, vector<int>>(genres[i], temp));
        }
        else
        {
            arr.find(genres[i])->second[0] += plays[i];
            if (arr.find(genres[i])->second[1] < plays[i])
            {
                arr.find(genres[i])->second[3] = arr.find(genres[i])->second[1];
                arr.find(genres[i])->second[4] = arr.find(genres[i])->second[2];
                arr.find(genres[i])->second[1] = plays[i];
                arr.find(genres[i])->second[2] = i;
            }
            else if (arr.find(genres[i])->second[3] < plays[i])
            {
                arr.find(genres[i])->second[3] = plays[i];
                arr.find(genres[i])->second[4] = i;
            }
        }
    }

    vector<pair<string, vector<int>>> v(arr.begin(), arr.end());
    sort(v.begin(), v.end(), cmp);

    for (auto it = arr.begin(); it != arr.end(); it++)
    {
        cout << it->first << ' ';
        for (int i = 0; i < 5; i++)
        {
            cout << it->second[i] << ' ';
        }
        cout << endl;
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].second[0] << ' ';
        answer.push_back(v[i].second[2]);
        if (v[i].second[4] != -1)
        {
            answer.push_back(v[i].second[4]);
        }
    }

    return answer;
}