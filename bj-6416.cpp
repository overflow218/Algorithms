#include <iostream>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

/*
1. 일단 루트가 한개인지 체크한다
2. 이제 루트부터 시작해서 올바른 트리인지 체크한다
u, v 는 13 이하의 자연수
*/

int inDegree[14] = {0};
int outDegree[14] = {0};
bool isVisited[14] = {false};
bool isValid[14] = {false}; // 등장한 수인지 체크
int maxNode = 0;
int minNode = 100;
int rootNode = 0;

vector<vector<int>> edges = vector<vector<int>>(14);

bool hasValidRoot()
{
    for(int i = 1; i <= 13; i++)
    {
        if(!isValid[i]) continue;
        if(inDegree[i] == 0){
            if(rootNode != 0) return false;
            rootNode = i;
        }
    }
    return true;
}

bool visit(int idx)
{
    if(isVisited[idx]) return false;
    isVisited[idx] = true;
    bool ret = true;
    for(auto & next: edges[idx])
    {
        ret &= visit(next);
    }

    return ret;
}

bool isValidTree()
{
    return visit(rootNode);
}

void initialize()
{
    maxNode = 0;
    minNode = 100;
    rootNode = 0;
    // edges.clear();
    edges = vector<vector<int>>(14);
    memset(inDegree, 0, sizeof(inDegree));
    memset(outDegree, 0, sizeof(outDegree));
    memset(isVisited, 0, sizeof(isVisited));
    memset(isValid, 0, sizeof(isValid));
}

int main()
{
    int u, v, cnt = 1;

    while (true){
        scanf("%d %d", &u, &v);
        if(u == -1 && v == -1) break;
        if(u == 0 && v == 0)
        {
            bool isValid = hasValidRoot() && isValidTree();
            if(isValid) printf("Case %d is a tree.\n", cnt);
            if(!isValid) printf("Case %d is not a tree.\n", cnt);
            initialize();
            cnt++;
        } else 
        {
            maxNode = max(maxNode, max(u, v));
            minNode = min(minNode, min(u, v));
            isValid[u] = true;
            isValid[v] = true;
            outDegree[u]++;
            inDegree[v]++;
            edges[u].push_back(v);
        }
    }
    
    return 0;
}