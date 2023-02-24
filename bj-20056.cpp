#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct fire {
    int x;
    int y;
    int m;
    int s;
    int d;
    bool alive;
};

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

queue<fire> q;
int main()
{
    int N, M, K, r, c, m, s, d;
    cin >> N >> M >> K;
    for(int i = 0; i < M; i++)
    {
        cin >> r >> c >> m >> s >> d;
        fire newBall = {r - 1, c - 1, m, s, d, true};
        q.push(newBall);
    }

    for(int it = 0; it < K; it++)
    {
        vector<fire> nextBall;
        int limit = q.size();
        for(int i = 0; i < limit; i++)
        {
            fire tmp = q.front();
            q.pop();
            int x = tmp.x, y = tmp.y, s = tmp.s, d = tmp.d, m = tmp.m;
            // 혹시나 틀리면 이부분 모듈로 계산 의심해보기
            int nx = (x + dx[d] * s + N * s) % N, ny = (y + dy[d] * s + N * s) % N;
            fire newBall = {nx, ny, m, s, d, true};
            nextBall.push_back(newBall);
        }

        // 겹치는게 없는지 체크해주기
        for(int i = 0; i < nextBall.size(); i++)
        {
            if(!nextBall[i].alive) continue;
            int totalMass = nextBall[i].m, totalSpeed = nextBall[i].s, cnt = 1;
            bool isEven = nextBall[i].d % 2 == 0, isOdd = nextBall[i].d % 2 == 1;

            for(int j = i + 1; j < nextBall.size(); j++)
            {
                // 앞에 애랑 겹쳐서 이미 처리해준 경우 
                if(!nextBall[j].alive) continue;
                if(nextBall[j].x == nextBall[i].x && nextBall[j].y == nextBall[i].y)
                {
                    nextBall[j].alive = false;
                    nextBall[i].alive = false;
                    totalMass += nextBall[j].m;
                    totalSpeed += nextBall[j].s;
                    cnt++;
                    if(nextBall[j].d % 2 == 1)
                    {
                        isOdd = true;
                    } else 
                    {
                        isEven = true;
                    }
                }
            }

            // 파이어볼 4개로 쪼개야함. 
            if(!nextBall[i].alive)
            {
                int x = nextBall[i].x, y = nextBall[i].y, s = totalSpeed / cnt, m = totalMass / 5;
                if(m > 0)
                {
                    int base = isEven && isOdd ? 1 : 0;
                    for(int i = 0; i < 4; i++)
                    {
                        fire newBall = {x, y, m, s, base + 2 * i, true};
                        q.push(newBall);
                    }
                }
            } else 
            {
                q.push(nextBall[i]);
            }
        }
    }


    int limit = q.size();
    int ans = 0;
    for(int i = 0; i < limit; i++)
    {
        fire tmp = q.front();
        q.pop();
        ans += tmp.m;
    }

    cout << ans << '\n';

    return 0;
}