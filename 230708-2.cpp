#include <iostream>
#include <vector>
using namespace std;

/*
이건 그냥 2 ^ M 번 단순탐색 진행하면됨. 
2^18 은 백만도 안되는 작은 수임
*/
int main() {
    int t, n, m, k;
    scanf("%d", &t);
    for(int test = 1; test <= t; test++)
    {
        scanf("%d %d %d", &n, &m, &k);
        vector<int> bulb(n + 1);
        vector<vector<int>> controller;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &bulb[i]);
        }
        for(int i = 0; i < m; i++)
        {
            vector<int> tmp(k);
            for(int j = 0; j < k; j++)
            {
                scanf("%d", &tmp[j]);
            }
            controller.push_back(tmp);
        }

        int limit = 1 << m;
        int ans = 100;
        for(int check = 0; check < limit; check++)
        {
            int cnt = 0;
            vector<int> tmpBulb(bulb.begin(), bulb.end());
            for(int j = 0; j < m; j++)
            {
                if(check & (1 << j))
                {
                    cnt++;
                    for(const int & num: controller[j])
                    {
                        tmpBulb[num]++;
                    }
                }
            }

            bool isPossible = true;
            for(int i = 1; i <= n; i++)
            {
                if(tmpBulb[i] % 2 == 0)
                {
                    isPossible = false;
                    break;
                }
            }
            if(isPossible) ans = min(ans, cnt);
        }
        printf("#%d %d\n", test, ans == 100 ? -1 : ans);
    }
    return 0;
}
