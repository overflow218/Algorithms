#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int arr[11][11] = {0};
int vitamin[11][11] = {0};
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
struct tree
{
    int x;
    int y;
    int age;
};

vector<vector<tree>> forest(1001);
set<int> s;
int main()
{
    int n, m, k, x, y, age;
    cin >> n >> m >> k;
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> vitamin[i][j];
            arr[i][j] = 5;
        }
    }

    for(int i = 0; i < m; i++)
    {
        cin >> x >> y >> age;
        tree newTree = {x, y, age};
        forest[age].push_back(newTree);
        s.insert(age);
    }

    int idx = 0;
    while(idx < k)
    {
        // 양분 못 먹어서 죽을녀석들
        vector<tree> die;
        // 살놈들
        vector<tree> active;

        // 봄 양분먹기
        for(const auto &ho:s)
        {
            for(int i = 0; i < forest[ho].size(); i++)
            {
                tree tmp = forest[ho][i];
                int x = tmp.x, y = tmp.y, age = tmp.age;
                if(arr[x][y] >= age)
                {
                    arr[x][y] -= age;
                    tmp.age = age + 1;
                    active.push_back(tmp);
                } else 
                {
                    die.push_back(tmp);
                }
            }
            forest[ho].clear();
        }

        s.clear();
        // 2. 여름 양분되기
        for(int i = 0; i < die.size(); i++)
        {
            int x = die[i].x, y = die[i].y, age = die[i].age;
            arr[x][y] += age / 2;
        }

        s.insert(1);
        // 3. 가을 번식해주기 
        for(int i = 0; i < active.size(); i++)
        {
            int x = active[i].x, y = active[i].y, age = active[i].age;
            forest[age].push_back(active[i]);
            s.insert(age);
            if(age % 5 != 0) continue;
            for(int j = 0; j < 8; j++)
            {
                int nx = x + dx[j], ny = y + dy[j];
                if(nx == 0 || nx > n || ny == 0 || ny > n) continue;
                tree newTree = tree{nx, ny, 1};
                forest[1].push_back(newTree);
            }
        }

        // 4. 겨울 양분 더해주기
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                arr[i][j] += vitamin[i][j];
            }
        }
        idx++;
    }

    int ans = 0;
    for(const auto &ho:s)
    {
        ans += forest[ho].size();
    }
    cout << ans << '\n';
    return 0;
}