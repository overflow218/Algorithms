#include <cstring>
using namespace std;

class Solution {
public:
    bool isVisited[10000] = {false};
    bool isDone[10000] = {false};
    // safe하면 1, 아니면 0, 모르면 -1
    int cache[10000];

    int find(int idx, vector<vector<int>>& graph)
    {
        int &ret = cache[idx];
        if(isDone[idx]) return ret;
        if(isVisited[idx]) return 0;
        ret = 1;
        isVisited[idx] = true;
        for(const int &out: graph[idx])
        {
            ret = min(ret, find(out, graph));
        }
        isDone[idx] = true;
        return ret;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        memset(cache, -1, sizeof(cache));
        int n = graph.size();
        for(int i = 0; i < n; i++)
        {
            if(!isVisited[i]) find(i, graph);
        }
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            if(cache[i] == 1) ans.push_back(i);
        }
        return ans;
    }
};