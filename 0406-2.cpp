#include <string>
#include <vector>
#include <cstring>
using namespace std;

bool isFixed[101];
bool isVisited[101];

vector<vector<int>> edges = vector<vector<int>>(101, vector<int>());
vector<int> vec;
vector<int> check;

void topo(int idx)
{
    if(isVisited[idx]) return;
    for(int i = 0; i < edges[idx].size(); i++)
    {
        topo(edges[idx][i]);
    }
    isVisited[idx] = true;
    vec.push_back(idx);
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    memset(isFixed, true, sizeof(isFixed));
    
    for(int i = 0; i < results.size(); i++)
    {
        edges[results[i][0]].push_back(results[i][1]);
    }
    
    for(int i = 1; i <= n; i++)
    {
        memset(isVisited, false, sizeof(isVisited));
        vec.clear();
        for(int j = 0; j < n; j++)
        {
            int start = ((i + j) % n) + 1;
            if(!isVisited[start]) topo(start);
        }
        if(check.empty()) {
            check = vector<int>(vec.begin(), vec.end());
        }
        
        for(int j = 0; j < n; j++)
        {
            if(check[j] != vec[j]) isFixed[j] = false;
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        if(isFixed[i]) answer++;
    }
    
    return answer;
}