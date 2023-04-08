#include <string>
#include <vector>
#include <cstring>
using namespace std;

int cache[100001] = {0};
const int MOD = 1000000007;

int solution(int n, vector<int> money) {
    cache[0] = 1;
    for(int i = 0; i < money.size(); i++)
    {
        int check = money[i];
        for(int j = 0; j <= n; j++)
        {
            if(j - check >= 0 && cache[j - check] > 0)
            {
                cache[j]+= cache[j - check];
                cache[j]%= MOD;
            }
        }
    }
    return cache[n];
}