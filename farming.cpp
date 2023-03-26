#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
using namespace std;

// 시작점, 펌프파워
multiset<pair<int, int>> IN;
// 끝점, 펌프파워
multiset<pair<int, int>> OUT;
// 현재 존재하는 파워들을 담고 있음
multiset<int> power;
// 마지막 시작점
int last = 0;
// 정답을 담고 있는 벡터
vector<vector<int>> ans;

void fun_in()
{
    int in = (*IN.begin()).first;
    // 현 시점 최고 높이
    int beforeHeight = *power.rbegin();
    while(!IN.empty() && (*IN.begin()).first == in)
    {
        power.insert((*IN.begin()).second);
        IN.erase(IN.begin());
    }
    int afterHeight = *power.rbegin();
    if(afterHeight > beforeHeight && last != in)
    {
        ans.push_back({last, in, beforeHeight});
        last = in;
    }
}

void fun_out()
{
    int out = (*OUT.begin()).first;
    // 현 시점 최고 높이
    int beforeHeight = *power.rbegin();
    while(!OUT.empty() && (*OUT.begin()).first == out)
    {
        power.erase(power.find((*OUT.begin()).second));
        OUT.erase(OUT.begin());
    }
    int afterHeight = power.empty() ? 0 : *power.rbegin();
    if(afterHeight < beforeHeight)
    {
        ans.push_back({last, out, beforeHeight});
        last = out;
    }
    if(OUT.empty() && last != out)
    {
        ans.push_back({last, out, 0});
    }
}

int main()
{
    int n, w, x, l, p;
    cin >> n >> w;
    
    for(int i = 0; i < n; i++)
    {
        cin >> x >> l >> p;
        IN.insert(make_pair(x - l, p));
        OUT.insert(make_pair(x + l, p));
    }
    power.insert(0);
    OUT.insert(make_pair(w, 0));

    while(!IN.empty())
    {
        int in = (*IN.begin()).first, out = (*OUT.begin()).first;
        if(in <= out)
        {
            fun_in();
        }
        if(out <= in)
        {
            fun_out();
        }
    }

    while(!OUT.empty())
    {
        fun_out();
    }

    printf("%d\n", (int)ans.size());
    for(int i = 0; i < ans.size(); i++)
    {
        printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
    }

    return 0;
}