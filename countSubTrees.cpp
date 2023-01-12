#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int alphabet[26] = {0};

    void dfs(int idx,vector<vector<int>>& graph, vector<int> & ans, string& labels)
    {
        int & ret = ans[idx];
        if(ret != 0) return;
        ret = 1;
        int prev = alphabet[labels[idx] - 'a'];
        alphabet[labels[idx] - 'a']++;
        for(int i = 0; i < graph[idx].size(); i++)
        {
            dfs(graph[idx][i], graph, ans, labels);
        }
        ret = alphabet[labels[idx] - 'a'] - prev;
        return;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> graph(n);
        vector<int> ans(n, 0);
        for(int i = 0; i < n - 1; i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(0, graph, ans, labels);

        return ans;
    }
};