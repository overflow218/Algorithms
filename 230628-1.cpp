#include <cstring>
class Solution {
public:
    vector<vector<pair<int, double>>> vec = vector<vector<pair<int, double>>>(10000);
    // cache[idx] = idx에서 시작해서 end까지 가는 최대 확률
    double cache[10000] = {0};
    bool isVisited[10000] = {false};
    double find(int idx, int end)
    {
        if(idx == end) return 1;
        double &ret = cache[idx];
        if(isVisited[idx]) return ret;
        isVisited[idx] = true;
        ret = 0;
        for(int i = 0; i < vec[idx].size(); i++)
        {
            int next = vec[idx][i].first;
            double prob = vec[idx][i].second;
            ret = max(ret, prob * find(next, end));
        }
        return ret;
    }
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        for(int i = 0; i < edges.size(); i++)
        {
            int a = edges[i][0], b = edges[i][1];
            vec[a].push_back(make_pair(b, succProb[i]));
            vec[b].push_back(make_pair(a, succProb[i]));
        }
        return find(start, end);
    }
};