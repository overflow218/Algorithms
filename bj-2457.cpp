#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct flower{
    pair<int, int> start;
    pair<int, int> end;
};

bool operator<(const flower& f1, const flower& f2)
{
    // 시작월이 빠른거 먼저
    if(f1.start != f2.start) return f1.start < f2.start;
    // 시작일이 같을땐 먼저 지는게 먼저
    return f1.end < f2.end;
}

void print(const flower& f1)
{
    printf("%d월%d일 -> %d월 %d일\n", f1.start.first, f1.start.second, f1.end.first, f1.end.second);
}

int main()
{
    int n, m1, m2, d1, d2;
    scanf("%d", &n);
    vector<flower> garden;

    for(int i = 0; i < n; i++)
    {
        scanf("%d %d %d %d", &m1, &d1, &m2, &d2);
        flower tmp_flower{make_pair(m1, d1), make_pair(m2, d2)};
        garden.push_back(tmp_flower);
    }

    sort(garden.begin(), garden.end());
    int month = 3, day = 1;
    int idx = 0, ans = 0;
    pair<int, int> now = make_pair(3, 1);
    pair<int, int> end = make_pair(12, 1);

    while(idx < n)
    {
        // 조건만족
        if(now >= end) break;

        flower cur = garden[idx];
        // 오늘날짜보다 작은 꽃 통과
        if(cur.end <= now)
        {
            idx++;
            continue;
        }

        pair<int, int> next = now;
        int next_idx = -1;
        for(int i = idx; i < n; i++)
        {
            // 뒤에 있는 꽃중 오늘날짜랑 겹치면서 제일 늦게까지 피는 꽃을 찾는다.
            if(garden[i].start <= now && next < garden[i].end)
            {
                next = garden[i].end;
                next_idx = i;
            }
            if(now < garden[i].start) break;
        }

        // 뒤에 더이상 조건을 만족하는 꽃이 없는거라서 실패임ㅋㅋ
        if(next_idx == -1) break;

        idx = next_idx;
        now = next;
        ans++;
    }


    printf("%d\n", now >= end ? ans : 0);
    return 0;
}