// #include <iostream>
// #include <queue>
// using namespace std;

// int board[101][101] = {0};
// bool isOn[101][101] = {false};

// // 0 오른쪽 1 아래 2 왼쪽 3 위
// int dx[] = {0, 1, 0, -1};
// int dy[] = {1, 0, -1, 0};

// struct position{
//     int x;
//     int y;
//     int direction;
// };

// int main()
// {
//     int n, k, x, y, l;
//     cin >> n >> k;

//     for(int i = 0; i < k; i++)
//     {
//         cin >> x >> y;
//         board[x][y] = 1;
//         printf("사과 %d, %d에 있음\n", x, y);
//     }

//     cin >> l;
//     queue<pair<int, char>> orders;
//     for(int i = 0; i < l; i++)
//     {
//         char tmp[3];
//         scanf("%d %s", &x, tmp);
//         orders.push(make_pair(x, tmp[0]));
//     }

//     int time = 0, size = 1;
//     position head = {1, 1, 0};
//     position tail = {1, 1, 0};
//     // <시간, 방향> 꼬리한테 방향 바꾸는거 알려주는 용도
//     queue<pair<int, int>> tailOrder;
//     isOn[1][1] = true;
//     while(true)
//     {
//         printf("time: %d, size: %d\n x: %d, y: %d, 꼬리 x: %d, y: %d\n", time, size, head.x, head.y,  tail.x, tail.y);
//         // printf("꼬리 위치 x: %d, y: %d\n", tail.x, tail.y);

//         // 1. 이동
//         int nx = head.x + dx[head.direction], ny = head.y + dy[head.direction];
//         // 벽과 부딪치거나 자기 몸이랑 부딪치면 바로 종료
//         if(nx == 0 || nx > n || ny == 0 || ny > n || isOn[nx][ny]){
//             if(isOn[nx][ny])
//             {
//                 cout << "지랑 부딪힘\n";
//             }
//             break;
//         } 

//         // 1-1. 사과 있으면 꼬리 그대로 없으면 꼬리 땡기기
//         head.x = nx; head.y = ny;
//         isOn[nx][ny] = true;
//         if(board[nx][ny] == 1)
//         {
//             printf("사과먹음\n");
//             board[nx][ny] = 0;
//             size++;
//         } else 
//         {
//             isOn[tail.x][tail.y] = false;
//             tail.x = tail.x + dx[tail.direction]; tail.y = tail.y + dy[tail.direction];            
//         }

//         // 2. 시간증가
//         time++;
//         // 3. 머리 방향전환
//         if(orders.front().first == time)
//         {
//             int op = orders.front().second == 'D' ? 1 : -1;
//             head.direction = (head.direction + 4 + op) % 4;
//             orders.pop();
//             tailOrder.push(make_pair(time + size - 1, head.direction));
//         }

//         // 4. 꼬리 방향전환
//         if(!tailOrder.empty() && tailOrder.front().first == time)
//         {
//             tail.direction = tailOrder.front().second;
//             tailOrder.pop();
//         }
//     }

//     printf("%d\n", time + 1);
//     return 0;
// }

#include <iostream>
#include <queue>
using namespace std;

int board[101][101] = {0};
bool isOn[101][101] = {false};

// 0 오른쪽 1 아래 2 왼쪽 3 위
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

struct position{
    int x;
    int y;
    int direction;
};

int main()
{
    int n, k, x, y, l;
    cin >> n >> k;

    for(int i = 0; i < k; i++)
    {
        cin >> x >> y;
        board[x][y] = 1;
    }

    cin >> l;
    queue<pair<int, char>> orders;
    for(int i = 0; i < l; i++)
    {
        char tmp[3];
        scanf("%d %s", &x, tmp);
        orders.push(make_pair(x, tmp[0]));
    }

    int time = 0, size = 1;
    position head = {1, 1, 0};
    position tail = {1, 1, 0};

    queue<pair<int, int>> tailOrder;
    isOn[1][1] = true;
    while(true)
    {
        // 1. 이동
        int nx = head.x + dx[head.direction], ny = head.y + dy[head.direction];
        // 벽과 부딪치거나 자기 몸이랑 부딪치면 바로 종료
        if(nx == 0 || nx > n || ny == 0 || ny > n || isOn[nx][ny]) break;

        // 1-1. 사과 있으면 꼬리 그대로 없으면 꼬리 땡기기
        head.x = nx; head.y = ny;
        isOn[nx][ny] = true;
        tailOrder.push(make_pair(nx, ny));
        if(board[nx][ny] == 1)
        {
            board[nx][ny] = 0;
            size++;
        } else 
        {
            isOn[tail.x][tail.y] = false;
            tail.x = tailOrder.front().first; tail.y = tailOrder.front().second;
            tailOrder.pop();     
        }

        // 2. 시간증가
        time++;
        // 3. 방향전환
        if(orders.front().first == time)
        {
            int op = orders.front().second == 'D' ? 1 : -1;
            head.direction = (head.direction + 4 + op) % 4;
            orders.pop();
        }
    }

    printf("%d\n", time + 1);
    return 0;
}