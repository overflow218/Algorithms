#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int arr[51][51] = {0};
int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, -1, 1};
int explode[4] = {0};

// check[i] = i 번째 수가 들어가야하는 (x,y)를 담고 있음.
vector<pair<int, int>> check(2500);
queue<int> ball;

void find(int x, int y, int n)
{
    if(n == 1)
    {
        return;
    }
    int start = n * n - 1;
    for(int i = 0; i < n; i++)
    {
        check[start] = make_pair(x, y + i);
        arr[x][y + i] = start;
        start--;
    }

    for(int i = 1; i < n; i++)
    {
        check[start] = make_pair(x + i, y + n - 1);
        arr[x + i][y + n - 1] = start;
        start--;
    }

    for(int i = 1; i < n; i++)
    {
        check[start] = make_pair(x + n - 1, y + n - 1 - i);
        arr[x + n - 1][y + n - 1 - i] = start;
        start--;
    }

    for(int i = 1; i < n - 1; i++)
    {
        check[start] = make_pair(x + n - 1 - i, y);
        arr[x + n - 1 - i][y] = start;
        start--;
    }
    find(x + 1, y + 1, n - 2);
}

// 구슬 터뜨리기
bool bomb()
{
    int limit = ball.size();
    int cnt = 0;
    bool isBombed = false;
    queue<int> tmp;

    for(int i = 0; i < limit; i++)
    {
        int cur = ball.front();
        ball.pop();
        // 연속하는 경우
        if(tmp.empty() || tmp.front() == cur)
        {
            tmp.push(cur);
            cnt++;
        } 
        // 연속하지 않는 경우
        else 
        {
            // 폭발하는 경우
            if(cnt >= 4)
            {
                isBombed = true;
                explode[tmp.front()] += cnt;
            } 
            // 폭발안하는 경우
            else 
            {
                while(!tmp.empty())
                {
                    ball.push(tmp.front());
                    tmp.pop();
                }
            }
            tmp = queue<int>();
            tmp.push(cur);
            cnt = 1;
        }
    }

    // 마지막으로 다시 체크
    // 폭발하는 경우
    if(cnt >= 4)
    {
        isBombed = true;
        explode[tmp.front()] += cnt;
    } 
    // 폭발안하는 경우
    else 
    {
        while(!tmp.empty())
        {
            ball.push(tmp.front());
            tmp.pop();
        }
    }
    return isBombed;
}

// 블리자드 후 이동하는 동작
void move(int n)
{
    vector<int> tmp;
    ball = queue<int>();
    for(int i = 1; i <= n * n - 1; i++)
    {
        int x = check[i].first, y = check[i].second;
        if(arr[x][y] > 0)
        {
            tmp.push_back(arr[x][y]);
        }
        // 0으로 덮어줘야 구슬을 이동시키기 편함.
        arr[x][y] = 0;
    }

    for(int i = 0; i < tmp.size(); i++)
    {
        // printf("%d ", tmp[i]);
        int x = check[i + 1].first, y = check[i + 1].second;
        arr[x][y] = tmp[i];
        ball.push(arr[x][y]);
    }
}

// 구슬이 터진후에 이동하는 동작
void move2(int n)
{
    vector<int> tmp;
    int limit = ball.size();
    for(int i = 1; i <= n * n - 1; i++)
    {
        int x = check[i].first, y = check[i].second;
        arr[x][y] = 0;
        if(i <= limit)
        {
            arr[x][y] = ball.front();
            ball.push(ball.front());
            ball.pop();
        }
    }
}

void change(int n)
{
    int limit = ball.size();
    int cur = -1, cnt = 0;
    vector<int> tmp;

    for(int i = 0; i < limit; i++)
    {
        int x = ball.front();
        ball.pop();
        // 연속하는 경우
        if(cur == -1 || cur == x)
        {
            cur = x;
            cnt++;
        } 
        // 연속하지 않는 경우
        else 
        {
            tmp.push_back(cnt);
            tmp.push_back(cur);
            cur = x;
            cnt = 1;
        }
    }

    // 맨 마지막것도 확인해줘야함. 
    if(cur != -1)
    {
        tmp.push_back(cnt);
        tmp.push_back(cur);
    }

    limit = min(n * n - 1, (int)tmp.size());
    for(int i = 0; i < limit; i++)
    {
        ball.push(tmp[i]);
    }

    // 이걸 arr에 반영을 해줘야하는데 지금 그게 빠졌음 ㅇㅇ..
}

int main()
{
    int n, m, d, s;

    cin >> n >> m;
    find(1, 1, n);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int sx = (n + 1) / 2, sy = (n + 1) / 2;
    
    for(int it = 0; it < m; it++)
    {
        cin >> d >> s;
        // 1. 블리자드 시전
        for(int i = 1; i <= s; i++)
        {
            int nx = sx + dx[d] * i, ny = sy + dy[d] * i;
            arr[nx][ny] = 0;
        }

        // 2. 구슬 터뜨릴 준비
        move(n);

        // // 더이상 없을때까지 터뜨리기
        while(bomb())
        {
            move2(n);
        }

        // 구슬 변화시키기
        change(n);
        move2(n);
    }

    int ans = explode[1] + 2 * explode[2] + 3 * explode[3];
    cout << ans << '\n';
    return 0;
}