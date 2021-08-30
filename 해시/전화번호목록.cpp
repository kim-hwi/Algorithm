#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool solution(vector<string> pb)
{
    bool answer = true;

    sort(pb.begin(), pb.end());
    for (int i = 0; i < pb.size() - 1; i++)
    {
        if (pb[i] == pb[i + 1].substr(0, pb[i].size()))
        {
            answer = false;
        }
    }

    return answer;
}