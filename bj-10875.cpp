#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

// 맨처음에는 오른쪽을 보고 있음. 
// L의 경우 반시계회전, R의 경우 시계방향 회전
// 0 -> 오른쪽, 1 아래, 2 <- 왼쪽, 3 위
int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};
const long long INF = 987654321;
// (시작점, 끝점, 축좌표, 타입정보 0은 가로, 1은 세로)
vector<tuple<int, int, int, int>> history;

vector<pair<int, char>> order;
int main()
{
    int l, n, t, idx = 0, x = 0, y = 0;
    char dir[2];
    long long ans = 0;

    cin >> l >> n;

    if(n == 0)
    {
        cout << l + 1 << '\n';
        return 0;
    }

    for(long long i = 0; i < n; i++)
    {
        scanf("%d %s", &t, dir);
        order.push_back(make_pair(t, dir[0]));
    }

    order.push_back(make_pair(2*l + 1, 'L'));
    for(long long i = 0; i <= n; i++)
    {
        t = order[i].first; char check = order[i].second;
        int nx = x + dx[idx] * t; int ny = y + dy[idx] * t;
        // 이전에 방문했던 점과 겹치는지 확인

        if(idx % 2 == 0)
        {
            int add = INF;
            for(const auto& line:history)
            {
                int s = get<0>(line), e = get<1>(line), axis = get<2>(line), type = get<3>(line);
                // 같은 방향일때 
                if(type == 0 && y == axis)
                {
                    if(x < s && s <= nx)
                    {
                        add = min(add, s - x);
                    } else if(x > e && nx <= e)
                    {
                        add = min(add, x - e);
                    } 
                } else if(type == 1)// 다른 방향일때
                {
                    // x축이 사이에 있으면서
                    if(min(x, nx) <= axis && axis <= max(x, nx) && axis != x)
                    {
                        // y축도 겹치는 경우
                        if(s <= y && y <= e)
                        {
                            // 제일 먼저 만나는 녀석을 찾아야함. 여기서 종료해버리면 안됨.
                            add = min(add, abs(x - axis));
                        }
                    }
                }
            }

            // 이전에 방문했던 점 방문시 바로 종료
            if(add != INF)
            {
                ans += (long long)add;
                break;
            }

            // 이전점과는 안부딪혀도 격자판 밖으로 나가면 바로 종료
            if(nx > l)
            {
                ans += (long long)(l - x + 1);
                break;
            } else if(nx < -l)
            {
                ans += (long long)(x + l + 1);
                break;
            }

            // 여기까지 왔으면 유효한 움직이이었음.
            history.push_back(make_tuple(min(x, nx), max(x, nx), y, 0));
        } 
        // 세로 방향으로 움직이니 garo check
        else 
        {
            int add = INF;
            for(const auto& line:history)
            {
                int s = get<0>(line), e = get<1>(line), axis = get<2>(line), type = get<3>(line);
                
                // 같은 방향일때 
                if(type == 1 && x == axis)
                {
                    if(y < s && s <= ny)
                    {
                        add = min(add, s - y);
                    } else if(y > e && ny <= e)
                    {
                        add = min(add, y - e);
                    }
                } else if(type == 0) // 다른 방향일때
                {
                    // y축이 사이에 있으면서
                    if(min(y, ny) <= axis && axis <= max(y, ny) && axis != y)
                    {
                        // x축도 겹치는 경우
                        if(s <= x && x <= e)
                        {
                            // 제일 먼저 만나는 녀석을 찾아야함. 여기서 종료해버리면 안됨.
                            add = min(add, abs(y - axis));
                        }
                    }
                }
            }

            // 이전에 방문했던 점 방문시 바로 종료
            if(add != INF)
            {
                ans += (long long)add;
                break;
            }

            // 이전점과는 안부딪혀도 격자판 밖으로 나가면 바로 종료
            if(ny > l)
            {
                ans += (long long)(l - y + 1);
                break;
            } else if(ny < -l)
            {
                ans += (long long)(y + l + 1);
                break;
            }

            // 여기까지 왔으면 유효한 움직이이었음.
            history.push_back(make_tuple(min(y, ny), max(y, ny), x, 1));
        }

        // 여기까지 왔으면 이번엔 무사함. 
        ans += (long long) t;
        // 반시계 회전
        if(check == 'L')
        {
            idx = (idx + 3) % 4;
        } else // 시계방향 회전
        {
            idx = (idx + 1) % 4;
        }
        x = nx; y = ny;
    }
    cout << ans << '\n';
    return 0;
}

/*
100000000
5
100000000 L
100000000 L
200000000 L
199999999 L
199999999 L
------- ans: 899999997 ok
1
6
1 L
1 L
2 L
2 L
2 L
3 L
------- 9 ok
1
0
------- 2 ok
4
6
2 L
1 R
1 R
3 R
2 R
1 L
------- 16 ok
3
1
1 L
------- 5 ok
3
4
2 L
2 L
1 L
5 R
------- 7 ok
3
3
2 L
4 L
4 R
------- 6 ok
4
4
1 L
1 L
2 L
1 L
------- 6 xxx
3
3
1 L
1 L
2 L
------- 9 ok
4
5
1 L
1 R
1 R
1 R
10 L
------- 5 ok
8
11
1 L
4 R
1 R
8 L
1 L
8 R
1 R
8 L
1 L
6 L
10 R
------- 40 ok
*/