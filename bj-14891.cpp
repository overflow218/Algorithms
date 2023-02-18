#include <iostream>
using namespace std;

char t[5][10];
int start[5] = {0, 0, 0, 0, 0};

// rotation = 1이면 시계방향, -1이면 반시계방향
// 시계방향 -1, 반시계 +1 만큼start를 늘려주면 됨. 
// 서로 다른극이면 반대방향으로 회전, 같은극이면 가만히 있음. 
void rotate(int idx, int rotation, int origin)
{
    // 왼쪽 체크
    if(idx > 1 && idx <= origin)
    {
        if(t[idx - 1][(start[idx - 1] + 2) % 8] != t[idx][(start[idx] + 6) % 8])
        {
            rotate(idx - 1, -rotation, origin);
        }
    }
    // 오른쪽 체크
    if(idx < 4 && origin <= idx)
    {
        if(t[idx][(start[idx] + 2) % 8] != t[idx + 1][(start[idx + 1] + 6) % 8])
        {
            rotate(idx + 1, -rotation, origin);
        }
    }
    start[idx] = (start[idx] + 8 - rotation) % 8;
}

int main()
{
    scanf("%s %s %s %s", t[1], t[2], t[3], t[4]);
    int k, x, rotation;
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        cin >> x >> rotation;
        rotate(x, rotation, x);
    }

    int ans = 0;
    if(t[1][start[1]] == '1') ans += 1;
    if(t[2][start[2]] == '1') ans += 2;
    if(t[3][start[3]] == '1') ans += 4;
    if(t[4][start[4]] == '1') ans += 8;
    cout << ans << '\n';
    return 0;
}