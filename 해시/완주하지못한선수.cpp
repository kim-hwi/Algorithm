#include <iostream>
#include <map>
#include <vector>
#include <string.h>

using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    string res = " ";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    for (int i = 0; i < participant.size(); i++)
    {
        if (participant[i] != completion[i])
        {
            res = participant[i];
            return res;
        }
    }
}
int main (void)
{
    
    vector<string> a;
    vector<string> b;
    a.push_back("leo");
    a.push_back("leo");
    a.push_back("leo");
    b.push_back("leo");
    b.push_back("leo");
    cout<<solution(a,b);
    // cout<<a.front()<<b.front();
    return 0;
}

