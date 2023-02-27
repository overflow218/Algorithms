#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

struct Group
{
    int x;
    int y;
    int rainbow;
    int size;
};

bool cmp(Group a, Group b)
{
    if(a.size != b.size) return a.size > b.size;
    if(a.rainbow != b.rainbow) return a.rainbow > b.rainbow;
    if(a.x != b.x) return a.x > b.x;
    return a.y > b.y;
}

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, m, rainbow = 0;
// 일반칸 1 ~ m, 무지개 0, 검은칸 -1, 빈칸 -2로 표현할거임
int arr[20][20];
bool isVisited[20][20];
vector<pair<int, int>> rainbowSpace;

int find(int x, int y, int color)
{
    // 범위 벗어나거나 검은색이거나 이미 방문한점은 종료
    if(x < 0 || x == n || y < 0 || y == n || arr[x][y] < 0 || isVisited[x][y]) return 0;
    // 같은 색 블록이 아니어도 종료
    if(arr[x][y] > 0 && arr[x][y] != color) return 0;

    isVisited[x][y] = true;
    if(arr[x][y] == 0)
    {
        rainbow++;
        rainbowSpace.push_back(make_pair(x, y));
    }
    
    int ret = 1;
    for(int i = 0; i < 4; i++)
    {
        ret += find(x + dx[i], y + dy[i], color);
    }
    return ret;
}

// (x, y)가 기준 블록인 블록그룹을 터뜨린다. 터뜨린자리에는 -2를 넣어줌
void bomb(int x, int y, int color)
{
    // 범위 벗어나거나 검은색이거나 이미 방문한점은 종료
    if(x < 0 || x == n || y < 0 || y == n || arr[x][y] < 0) return;
    // 같은 색 블록이 아니어도 종료
    if(arr[x][y] > 0 && arr[x][y] != color) return;

    arr[x][y] = -2;
    for(int i = 0; i < 4; i++)
    {
        bomb(x + dx[i], y + dy[i], color);
    }
}

void rotate()
{
    int tmp[20][20];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            tmp[i][j] = arr[j][n - 1 - i];
        }
    }
    memcpy(arr, tmp, sizeof(arr));
}

void gravity()
{
    for(int col = 0; col < n; col++)
    {
        int lastIdx = n - 1;
        queue<int> q;
        for(int row = n - 1; row >= 0; row--)
        {
            if(arr[row][col] == -2) continue;
            if(arr[row][col] > -1)
            {
                q.push(arr[row][col]);
                arr[row][col] = -2;
            } else if(arr[row][col] == -1)
            {
                int limit = q.size();
                for(int i = 0; i < limit; i++)
                {
                    int x = q.front();
                    q.pop();
                    arr[lastIdx][col] = x;
                    lastIdx--;
                }
                lastIdx = row - 1;
            }
        }
        // 혹시나 남아있는 애들 처리
        int limit = q.size();
        for(int i = 0; i < limit; i++)
        {
            int x = q.front();
            q.pop();
            arr[lastIdx][col] = x;
            lastIdx--;
        }
    }
}

void debug()
{
    printf("----------debug------------\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int score = 0;
    int ho = 0;
    while(true)
    {
        ho++;
        vector<Group> check;
        memset(isVisited, 0, sizeof(isVisited));

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(arr[i][j] <= 0 || isVisited[i][j]) continue;
                rainbow = 0;
                int cnt = find(i, j, arr[i][j]);
                if(cnt > 1)
                {
                    Group newGroup = {i, j, rainbow, cnt};
                    check.push_back(newGroup);
                }
                for(int k = 0; k < rainbowSpace.size(); k++)
                {
                    isVisited[rainbowSpace[k].first][rainbowSpace[k].second] = false;
                }
                rainbowSpace.clear();
            }
        }

        if(check.empty()) break;

        sort(check.begin(), check.end(), cmp);
        int x = check[0].x, y = check[0].y;
        score += check[0].size * check[0].size; 
        bomb(x, y, arr[x][y]);
        gravity();
        rotate();
        gravity();
    }

    cout << score << '\n';
    return 0;
}