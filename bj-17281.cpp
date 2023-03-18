#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int inning[50][9] = {0};
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cin >> inning[i][j];
        }
    }
    int ans = 0;
    vector<int> order = {1, 2, 3, 4, 5, 6, 7, 8};
    do {
        vector<int> tmpOrder;
        
        for(int i = 0; i < 8; i++)
        {
            if(i == 3) tmpOrder.push_back(0);
            tmpOrder.push_back(order[i]);
        }

        int score = 0, idx = 0;
        for(int i = 0; i < n; i++)
        {
            int outCount = 0;
            bool base[4] = {0};
            while(outCount < 3)
            {
                int hitter = tmpOrder[idx];
                idx = (idx + 1) % 9;
                int run = inning[i][hitter];
                base[0] = true;
                if(run == 0)
                {
                    outCount++;
                } else 
                {
                    for(int j = 3; j >= 0; j--)
                    {
                        // j루에 주자가 있을때
                        if(base[j])
                        {
                            // 홈에 들어오는 경우
                            if(j + run >= 4)
                            {
                                score++;
                            } 
                            // 진루하는 경우
                            else 
                            {
                                base[j + run] = true;
                            }
                            // 언제든 현재 베이스는 비워준다
                            base[j] = false;
                        }
                    }
                }
            }
        }
        ans = max(ans, score);
    } while (next_permutation(order.begin(), order.end()));

    cout << ans << '\n';
    return 0;
}