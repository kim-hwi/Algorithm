#include <string>
#include <vector>
#include <map>
#include <tuple>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays)
{
    map<string, vector<int>> arr;
    for (int i = 0; i < genres.size(); i++)
    {
        if(arr.find(genres[i]) == arr.end()){
            arr.insert(pair<string,vector<int>>(genres[i],(plays[i],plays[i],plays[i])));
        }
        else
        {
            arr.find(genres[i])->second[0] +=plays[i];
            if (arr.find(genres[i])->second[1] < plays[i])
        }
    }
    vector<int> answer;
    return answer;
}
int main (void){
    return 0;
}