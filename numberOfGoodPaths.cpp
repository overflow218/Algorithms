#include <map>
class Solution {
public:
    int parent[30000];

    int find(int x)
    {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void make_union(int x, int y)
    {
        x = find(x);
        y = find(y);
        if(x < y)
        {
            parent[y] = x;
        } else 
        {
            parent[x] = y;
        }
    }

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<vector<int>> graph(n);
        vector<bool> isVisited(n, false);
        for(int i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        map<int, vector<int>> level;
        for(int i = 0; i < n; i++)
        {
            level[vals[i]].push_back(i);
        }

        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
        int ans = 0;

        auto it = level.begin();
        while(it != level.end())
        {
            int stage = it->first;
            vector<int> nodes = it -> second;

            for(auto& node:nodes)
            {
                for(auto& neighbor: graph[node])
                {
                    if(vals[neighbor] <= vals[node])
                    {
                        make_union(node, neighbor);
                    }
                }
            }
            unordered_map<int, int> count;
            for(auto& node : nodes)
            {
                count[find(node)]++;
            }

            for(auto& [key, val]: count)
            {
                ans += val * (val + 1) / 2;
            }
            it++;
        }
        return ans;
    }
};