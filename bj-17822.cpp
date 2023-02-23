#include <iostream>
#include <vector>
using namespace std;

// 각 판의 내용
int plate[51][50];
// 각 판별 시작점
int start[51] = {0};

int main()
{
    int n, m, t, x, d, k;

    cin >> n >> m >> t;
    // 각 판별 시작점을 가지고 있음.
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> plate[i][j];
        }
    }

    for(int it = 0; it < t; it++)
    {
        cin >> x >> d >> k;
        // x의 배수인 원판을 d방향으로 k칸 회전시킴
        // 0이면 시계, 1이면 반시계
        for(int i = x; i <= n; i += x)
        {
            if(d == 0)
            {
                start[i] = (start[i] + m - k) % m;
            } else 
            {
                start[i] = (start[i] + k) % m;
            }
        }

        // 인접한 수가 있는 경우 다 지운다. 지우는 수는 0으로 바꿔줄거임
        bool isDuplicate[51][50] = {false};
        bool notDuplicate = true;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int idx = (start[i] + j) % m;
                int left = (start[i] + j + m - 1) % m;
                int right = (start[i] + j + 1) % m;

                // 수평방향으로는 확인
                if(plate[i][idx] != 0 && plate[i][idx] == plate[i][left])
                {
                    isDuplicate[i][idx] = isDuplicate[i][left] = true;
                    notDuplicate = false;
                }
                if(plate[i][idx] != 0 && plate[i][idx] == plate[i][right])
                {
                    isDuplicate[i][idx] = isDuplicate[i][right] = true;
                    notDuplicate = false;
                }

                // 수직방향 확인
                if(i > 1)
                {
                    int bottom = (start[i - 1] + j) % m;
                    if(plate[i][idx] != 0 && plate[i][idx] == plate[i - 1][bottom])
                    {
                        isDuplicate[i][idx] = isDuplicate[i - 1][bottom] = true;
                        notDuplicate = false;
                    }
                }
                if(i < n)
                {
                    int up = (start[i + 1] + j) % m;
                    if(plate[i][idx] != 0 && plate[i][idx] == plate[i + 1][up])
                    {
                        isDuplicate[i][idx] = isDuplicate[i + 1][up] = true;
                        notDuplicate = false;
                    }
                }
            }
        }

        int sum = 0;
        vector<pair<int, int>> candidate;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(isDuplicate[i][j])
                {
                    plate[i][j] = 0;
                }
                if(plate[i][j] > 0)
                {
                    sum += plate[i][j];
                    candidate.push_back(make_pair(i, j));
                }
            }
        }

        // 평균 구해서 평균보다 낮은 넘들은 +1, 높은 놈들은 -1 해줄거임
        if(notDuplicate)
        {
            int cnt = candidate.size();
            for(int i = 0; i < cnt; i++)
            {
                int x = candidate[i].first, y = candidate[i].second;
                if(plate[x][y] * cnt > sum)
                {
                    plate[x][y]--;
                }else if(plate[x][y] * cnt < sum)
                {
                    plate[x][y]++;
                }
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            ans += plate[i][j];
        }
    }

    cout << ans <<'\n';
    return 0;
}