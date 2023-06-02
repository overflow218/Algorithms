#include "jelly.h"
using namespace std;

vector<int> ans;
int find(vector<int> vec)
{
    if(vec.size() == 1) return vec[0];
    int mid = vec.size() / 2;

    vector<int> left(vec.begin(), vec.begin() + mid);
    vector<int> right(vec.begin() + mid, vec.end());
    vector<int> tmp(ans.begin(), ans.end());

    for(int i = 0; i < left.size(); i++)
    {
        tmp.push_back(left[i]);
    }

    // 왼쪽에 들어있는 상황임.
    if(query(tmp) == query(left)) return find(left);
    
    // 오른쪽에 들어있는 상황임.
    return find(right);
}

std::vector<int> start(int N)
{
    vector<int> leftJelly;
    if(N == 1) return {1};

    for(int i = 1; i <= N; i++)
    {
        leftJelly.push_back(i);
    }

    for(int i = 0; i < N; i++)
    {
        vector<int> tmp(leftJelly.begin(), leftJelly.end());
        tmp.erase(tmp.begin() + i);
        // i + 1을 시작으로 삼아도 좋음. 
        if(query(tmp) == 1)
        {
            ans.push_back(i + 1);
            leftJelly.erase(leftJelly.begin() + i);
            break;
        }
    }
    
    for(int t = 0; t < N - 1; t++)
    {
        int next = find(leftJelly);
        for(int i = 0; i < leftJelly.size(); i++)
        {
            if(leftJelly[i] == next)
            {
                leftJelly.erase(leftJelly.begin() + i);
                break;
            }
        }
        ans.push_back(next);
    }

    return ans;
}

/*
5
4 2 3 1 5

8
1 7 2 3 6 5 4 8

8
1 7 8 2 3 6 5 4
*/