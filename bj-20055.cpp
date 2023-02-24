#include <iostream>
#include <cstring>
using namespace std;

int stamina[210];
bool robot[210];
int main()
{
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < 2 * n; i++)
    {
        cin >> stamina[i];
    }

    int cnt = 0, start = 0;
    const int MOD = 2 * n;
    while(true)
    {
        cnt++;

        // 0. 내리는 칸에 있는놈은 자동으로 내림. 
        robot[(start + n - 1) % MOD] = false;
        // 1. 벨트 한칸 회전. 회전전에 내리는 칸에 있는애는 내림
        start = (start + MOD - 1) % MOD;
        robot[(start + n - 1) % MOD] = false;

        // 2. robot들의 한칸 이동
        for(int i = n - 2; i >= 1; i--)
        {
            int cur = (start + i) % MOD;
            int next = (start + i + 1) % MOD;
            if(robot[cur] && !robot[next] && stamina[next] > 0)
            {
                robot[next] = true;
                robot[cur] = false;
                stamina[next]--;
            }
        }

        // 3. 올리는칸의 내구도가 0이 아니면 하나 올리기
        if(stamina[start] > 0)
        {
            robot[start] = true;
            stamina[start]--;
        }

        // 4. k칸 이상이 내구도 0이면 종료
        int sum = 0;
        for(int i = 0; i < MOD; i++)
        {
            if(stamina[i] == 0)
            {
                sum++;
            }
        }
        if(sum >= k) break;
    }

    cout << cnt << '\n';
    return 0;
}