#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int c, n, m, x, y;
// x와 y가 친구면 isFriend[x][y] = isFriend[y][x] = true, 아니면 false
bool isFriend[10][10] = {0};

// i번 학생이 짝 지어졌으면 참, 아니면 거짓.
bool isMatched[10] = {0};

// 짝 안지어진 학생중 가장 작은 번호 리턴. 모두 짝 있으면 n 리턴
int notMatchedStudent()
{
    for(int i = 0; i < n; i++)
    {
        if(!isMatched[i]) return i;
    }
    return n;
}

int find()
{
    int idx = notMatchedStudent();
    if(idx == n)
    {
        return 1;
    }
    int ans = 0;
    isMatched[idx] = true;
    for(int i = idx + 1; i < n; i++)
    {
        // 친구이면서 아직 짝이 없을때 짝지어준다
        if(isFriend[idx][i] && !isMatched[i])
        {
            isMatched[i] = true;
            ans += find();
            isMatched[i] = false;
        }
    }
    isMatched[idx] = false;
    return ans;
}

int main()
{
    scanf("%d", &c);
    for(int t = 0; t < c; t++)
    {
        scanf("%d %d", &n, &m);
        memset(isMatched, 0, sizeof(isMatched));
        memset(isFriend, 0, sizeof(isFriend));

        for(int i = 0; i < m; i++)
        {
            scanf("%d %d", &x, &y);
            isFriend[x][y] = true;
            isFriend[y][x] = true;
        }
        printf("%d\n", find());
    }
    return 0;
}