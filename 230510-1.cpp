#include <iostream>
#include <vector>
using namespace std;

vector<int> last = vector<int>(500001, -1);
int count[500001] = {0};
bool isDone[500001] = {false};

int solution(std::vector<int> a) {
    int ans = 0;
    for(int i = 0; i < a.size(); i++)
    {
        int cur = a[i];
        int diff = i - last[cur];
        if(diff >= 2)
        {
            count[cur]++;
            if(last[cur] == -1)
            {
                isDone[cur] = true;
            }
            if(last[cur] > -1)
            {
                if(!isDone[cur] && diff > 2)
                {
                    isDone[cur] = true;
                    count[cur]++;
                }
            }
        }
        if(diff == 1) isDone[cur] = false;
        last[cur] = i;
    }
    for(int i = 0; i <= a.size(); i++)
    {
        if(!isDone[i] && last[i] < a.size() - 1) count[i]++;
        ans = max(ans, count[i]);
    }
    return ans * 2;
}