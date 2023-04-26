#include <string>
#include <vector>
using namespace std;

int cache[151][151] = {0};
int tA, tC;
int find(int algo, int code, vector<vector<int>> &problems)
{
    int tmpA = min(algo, tA), tmpC = min(code, tC);
    if(tmpA == tA && tmpC == tC) return 0;   
    int &ret = cache[tmpA][tmpC];
    if(ret != 0) return ret;
    
    ret = 987654321;
    if(algo < tA) ret = min(find(algo + 1, code, problems) + 1, ret);
    if(code < tC) ret = min(find(algo, code + 1, problems) + 1, ret);
    
    for(const auto & prob: problems)
    {
        if(algo >= prob[0] && code >= prob[1])
        {
            ret = min(ret, find(algo + prob[2], code + prob[3], problems) + prob[4]);   
        }
    }
    return ret;
}

int solution(int alp, int cop, vector<vector<int>> problems) {
    for(const auto & prob: problems)
    {
        tA = max(tA, prob[0]);
        tC = max(tC, prob[1]);
    }
    return find(alp, cop, problems);
}