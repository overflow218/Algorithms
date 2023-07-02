#include <algorithm>
class Solution {
public:
    bool isDone[20] = {false};
    vector<vector<int>> check;
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a.size() > b.size();
    }
    void find(int current, vector<int> &chosen, vector<bool> &isVisited, vector<vector<int>>& requests)
    {
        for(int i = 0; i < requests.size(); i++)
        {
            int from = requests[i][0], to = requests[i][1];
            if(isVisited[to] || current != from) continue;
            chosen.push_back(i);
            isVisited[to] = true;
            if(to == requests[chosen[0]][0])
            {
                check.push_back(chosen);
            } else 
            {
                find(to, chosen,isVisited, requests);
            }
            isVisited[to] = false;
            chosen.pop_back();
        }
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> chosen;
        vector<bool> isVisited(20, false);
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            find(i, chosen, isVisited, requests);
        }
        sort(check.begin(), check.end(), cmp);
        for(int i = 0; i < check.size(); i++)
        {
            bool isPossible = true;
            for(int j = 0; j < check[i].size(); j++)
            {
                if(isDone[check[i][j]])
                {
                    isPossible = false;
                    break;
                }
            }
            if(isPossible)
            {
                ans += check[i].size();
                for(int j = 0; j < check[i].size(); j++)
                {
                    int from = requests[check[i][j]][0], to = requests[check[i][j]][1];
                    isDone[check[i][j]] = true;
                }
            }
        }
        return ans;
    }
};