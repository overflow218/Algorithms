#include "jelly.h"
using namespace std;

std::vector<int> start(int N)
{
    std::vector<int> ans;
    vector<bool> isDone(N + 1, false);
    ans.push_back(1);
    isDone[1] = true;
    

    while(ans.size() < N)
    {
        for(int i = 1; i <= N; i++)
        {
            if(isDone[i]) continue;
            vector<int> vec(ans.begin(), ans.end());
            vec.push_back(i);
            int result = query(vec);
            if(result == 1)
            {
                isDone[i] = true;
                ans.push_back(i);
            }
        }
    }
    

    return ans;
}