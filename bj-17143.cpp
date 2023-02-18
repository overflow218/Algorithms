#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct shark{
    int x;
    int y;
    int speed;
    int direction;
    int size;
};

int dx[] = {0, -1, 1, 0};
int dy[] = {-1, 0, 0, 1};
int arr[101][101] = {0};
int main()
{
    int r, c, m, x, y, speed, direction, size;
    cin >> r >> c >> m;

    int position = 0, ans = 0;
    queue<shark> cage;
    for(int i = 0; i< m; i++)
    {
        cin >> x >> y >> speed >> direction >> size;
        speed = direction <= 2 ? speed % (2 * r - 2) : speed % (2 * c - 2);
        direction %= 4;
        shark newShark = {x, y, speed, direction, size};
        cage.push(newShark);
    }

    while(!cage.empty() && position < c)
    {
        // 오른쪽으로 1칸 이동
        position++;
        // 잡을 수 있는 상어 있는지 체크
        int height = 200, limit = cage.size();
        queue<shark> candidate;
        for(int i = 0; i < limit; i++)
        {
            shark tmp = cage.front();
            cage.pop();
            if(tmp.y == position && tmp.x <= height)
            {
                height = tmp.x;
                candidate.push(tmp);
            } else 
            {
                cage.push(tmp);
            }
        }

        // 잡을 수 있는 상어가 있는 경우
        if(height != 200)
        {
            int limit = candidate.size();
            int add = 0;
            for(int i = 0; i < limit; i++)
            {
                shark tmp = candidate.front();
                candidate.pop();
                if(tmp.x == height)
                {
                    add = max(add, tmp.size);
                } else 
                {
                    // 제일 위에 있는애가 아니면 다시 넣어주기
                    cage.push(tmp);
                }
            }
            ans += add;
        }

        // 상어의 이동
        limit = cage.size();
        for(int i = 0; i < limit; i++)
        {
            shark tmp = cage.front();
            cage.pop();
            int x = tmp.x, y = tmp.y, direction = tmp.direction, speed = tmp.speed, size = tmp.size;
            // <- 왼쪽으로 이동
            if(direction == 0 && speed > 0)
            {
                if(speed < y - 1)
                {
                    y -= speed;
                } else if(speed < y + c - 2)
                {
                    direction = 3;
                    speed -= y - 1;
                    y = 1 + speed;
                } else 
                {
                    speed -= y + c - 2;
                    y = c - speed;
                }
            } 
            // -> 오른쪽 이동
            else if(direction == 3 && speed > 0)
            {
                if(speed < c - y)
                {
                    y += speed;
                } else if(speed < 2 * c - y - 1)
                {
                    speed -= c - y;
                    direction = 0;
                    y = c - speed;
                } else 
                {
                    speed -= 2 * c - y -1;
                    y = 1 + speed;
                }
            } 
            // 위로 이동
            else if(direction == 1 && speed > 0)
            {
                if(speed < x - 1)
                {
                    x -= speed;
                } else if(speed < x + r - 2)
                {
                    speed -= x - 1;
                    direction = 2;
                    x = 1 + speed;
                } else 
                {
                    speed -= x + r - 2;
                    x = r - speed;
                }
            } 
            // 아래로 이동
            else if(direction == 2 && speed > 0)
            {
                if(speed < r - x)
                {
                    x += speed;
                } else if(speed < 2 * r - x - 1)
                {
                    speed -= r - x;
                    direction = 1;
                    x = r - speed;
                } else 
                {
                    speed -= 2 * r - x - 1;
                    x = 1 + speed;
                }
            }
            tmp.x = x;
            tmp.y = y;
            tmp.direction = direction;
            cage.push(tmp);
            arr[tmp.x][tmp.y] = max(tmp.size, arr[tmp.x][tmp.y]);
        }
        for(int i = 0; i < limit; i++)
        {
            shark tmp = cage.front();
            cage.pop();
            int x = tmp.x, y = tmp.y, direction = tmp.direction, speed = tmp.speed, size = tmp.size;
            if(arr[x][y] == tmp.size)
            {
                cage.push(tmp);
                arr[x][y] = 0;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}