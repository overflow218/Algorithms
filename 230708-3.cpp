#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
/*
동전으로 만들 수 있는 가능한 모든 경우를 구하는건 
너무 경우의 수가 많아서 힘들어 보임. 
차라리 특정 x에 대해 가진 동전 3개를 조합해서 만들 수 있는지 여부를
반환하도록 하는게 훨씬 좋은 선택인 것 같음.
*/

set<int> s;
int main() {
    int t, n, m;
    scanf("%d", &t);
    for(int test = 1; test <= t; test++)
    {
        scanf("%d %d", &n, &m);
        vector<int> coin(n);
        vector<int> goods(m);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &coin[i]);
        }
        for(int i = 0; i < m; i++)
        {
            scanf("%d", &goods[i]);
        }
        sort(goods.begin(), goods.end());
        s.clear();

        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                s.insert(coin[i] + coin[j]);
            }
        }

        vector<int> possible;
        for(int k = 0; k < m; k++)
        {
            for(int i = 0; i < n; i++)
            {
                int left = goods[k] - coin[i];
                if(left <= 0) continue;
                if(s.find(left) != s.end())
                {
                    possible.push_back(goods[k]);
                    break;
                }
            }
        }
        
        if(possible.empty())
        {
            printf("#%d -1\n", test);    
        } else 
        {
            printf("#%d %d %d\n", test, possible[0], possible.back());
        }
    }
    return 0;
}
