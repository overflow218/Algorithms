#include <string>
#include <vector>
using namespace std;

int cache[100100][2] = {0};
vector<int> solution(int target) {
    for(int i = 0; i <= target; i++)
    {
        for(int j = 1; j <= 20; j++)
        {
            for(int k = 1; k <= 3; k++)
            {
                int next = i + j * k;
                if(cache[i][0] + 1 == cache[next][0] && cache[i][1] >= cache[next][1])
                {
                    cache[next][1] = k == 1 ? cache[i][1] + 1 : cache[i][1];
                }
                if(cache[next][0] == 0 || cache[i][0] + 1 < cache[next][0])
                {
                    cache[next][0] = cache[i][0] + 1;
                    cache[next][1] = k == 1 ? cache[i][1] + 1 : cache[i][1];
                }
            }
        }
        
        int next = i + 50;
        if(cache[i][0] + 1 == cache[next][0] && cache[i][1] >= cache[next][1])
        {
            cache[next][1] = cache[i][1] + 1;
        }
        if(cache[next][0] == 0 || cache[i][0] + 1 < cache[next][0])
        {
            cache[next][0] = cache[i][0] + 1;
            cache[next][1] = cache[i][1] + 1;
        }
    }
    return {cache[target][0], cache[target][1]};
}