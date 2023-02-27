#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[20][20] = {0};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct Position 
{
    int x;
    int y;
    int like;
    int empty;
};

struct Student 
{
    int x;
    int y;
    int a;
    int b;
    int c;
    int d;
};


bool cmp(Position a, Position b)
{
    if(a.like != b.like) return a.like > b.like;
    if(a.empty != b.empty) return a.empty > b.empty;
    if(a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

vector<Student> classRoom;
int main()
{
    int n, s, a, b, c, d;
    cin >> n;
    for(int it = 0; it < n * n; it++)
    {
        cin >> s >> a >> b >> c >> d;
        vector<Position> check;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(arr[i][j] > 0) continue;
                // 빈칸인 경우
                Position newPosition = {i, j, 0, 0};
                for(int k = 0; k < 4; k++)
                {
                    int nx = i + dx[k], ny = j + dy[k];
                    // 범위 벗어나는 경우 컷
                    if(nx < 0 || nx == n || ny < 0 || ny == n) continue;
                    if(arr[nx][ny] == 0) newPosition.empty++;
                    if(arr[nx][ny] == a || arr[nx][ny] == b || arr[nx][ny] == c || arr[nx][ny] == d) newPosition.like++;
                }
                check.push_back(newPosition);
            }
        }

        sort(check.begin(), check.end(), cmp);
        int x = check[0].x, y = check[0].y;
        arr[x][y] = s;
        Student newStudent = {x, y, a, b, c, d};
        classRoom.push_back(newStudent);
    }

    int ans = 0;
    for(const auto & student: classRoom)
    {
        int x = student.x, y = student.y;
        int cnt = 0;
        for(int k = 0; k < 4; k++)
        {
            int nx = x + dx[k], ny = y + dy[k];
            // 범위 벗어나는 경우 컷
            if(nx < 0 || nx == n || ny < 0 || ny == n) continue;
            if(arr[nx][ny] == student.a || arr[nx][ny] == student.b || arr[nx][ny] == student.c || arr[nx][ny] == student.d) cnt++;
        }
        ans += (int)pow(10, cnt - 1);
    }

    cout << ans <<'\n';
    return 0;
}