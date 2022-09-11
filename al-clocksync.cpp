#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

// i번 스위치와 연결된 시계들의 번호를 담고 있는 벡터
vector<vector<int> > clockSwitch = {
    {0, 1, 2},
    {3, 7, 9, 11},
    {4, 10, 14, 15},
    {0, 4, 5, 6, 7},
    {6, 7, 8, 10, 12},
    {0, 2, 14, 15},
    {3, 14, 15}, 
    {4, 5, 7, 14, 15},
    {1, 2, 3, 4, 5}, 
    {3, 4, 5, 9, 13}
};
// 현재 시계가 가르키는 값. 이거 귀찮아서 그냥 계속 +3 더하는 방식으로 구현할거임. 
// 나중에 isDone 부분에서 체크할때 % 12로 확인해줄거임. 
int clockValue[16] = {0};
int ans = 987654321;

// 시계가 다 12시 가르키고 있으면 참, 아니면 거짓
bool isDone()
{
    for(int i = 0; i < 16; i++)
    {
        if(clockValue[i] % 12) return false;
    }
    return true;
}

// idx번 스위치를 살펴봄, cnt는 현재까지 오면서 누른 스위치의 갯수
void find(int idx, int cnt)
{
    if(isDone())
    {
        ans = min(ans, cnt);
        return;
    }
    if(idx == 10) return;
    // 각 스위치별로 4번 이상 누르는건 의미가 없음
    for(int i = 1; i <= 4; i++)
    {
        for(int j = 0; j < clockSwitch[idx].size(); j++)
        {
            clockValue[clockSwitch[idx][j]] += 3;
        }
        find(idx + 1, cnt + (i % 4));
    }
}

int main()
{
    int c; 
    scanf("%d", &c);
    for(int t = 0; t < c; t++)
    {
        ans = 987654321;
        for(int i = 0; i < 16; i++)
        {
            scanf("%d", &clockValue[i]);
        }
        find(0, 0);
        printf("%d\n", ans == 987654321 ? -1 : ans);
    }
    return 0;
}