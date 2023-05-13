#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<long long, long long>> vec = vector<pair<long long, long long>>(1000000);

bool cmp(pair<long long, long long> p1, pair<long long, long long> p2)
{
    return p1.second > p2.second;
}

// left부터 right까지의 범위가 그 안에서 구할 수 있는 최대 직사각형 크기
long long find(int left, int right)
{
    // base case
    if(left == right) return vec[left].first * vec[left].second;

    int mid = (left + right) / 2;
    // 일단 왼쪽에서 구한거, 오른쪽에서 구한거 각각 재귀 호출
    long long ret = max(find(left, mid), find(mid + 1, right));

    // 이제 가운데에서부터 하나씩 늘려가면서 찾을 수 있는 최대 크기 탐색
    int l = mid, r = mid + 1;
    long long height = min(vec[l].second, vec[r].second);
    long long width = vec[l].first + vec[r].first;
    ret = max(ret, height * width);

    while(left < l || r < right)
    {
        // 오른쪽으로 가야하는 상황
        // 왼쪽이 이미 다 봤거나, 오른쪽 왼쪽 다 남아있고, 오른쪽이 높이가 더 높은 경우
        if(left == l || (r < right && (vec[r + 1].second > vec[l - 1].second)))
        {
            height = min(height, vec[r + 1].second);
            width += vec[r + 1].first;
            r++;
        }
        // 왼쪽으로 가야하는 상황
        else {
            height = min(height, vec[l - 1].second);
            width += vec[l - 1].first;
            l--;
        }
        ret = max(ret, height * width);
    }
    return ret;
}
int main()
{
    int n, x, y;
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &x, &y);
        vec[i] = make_pair(x, y);
    }

    /*
    조건이 붙은경우에는 문제에 입력으로 주어진거 그대로 사용해야함.
    이때 왼쪽 나무, 오른쪽 나무가 선택된다면 width가 정해지게 되고, 높이는 그 사이의 최소의 높이가 됨.
    width구하는건 부분합 쓰면 쉬운데, height도 쉬울까? 일단 임의의 구간에 hegith를 구하는것도 어렵고
    만약 쉽게 구한다하더라고 왼쪽나무, 오른쪽 나무 선택가능한 경우의 수가 nC2인데 n이 10^6이라서 너무 경우의수가 많음
    DP 사용한다하더라도 너무 많은 숫자임. 
    Divide & Conquer를 사용해보는게 어떨까 싶네
    */

    // 조건 없는거, 조건 있는거
    long long ans1 = 0, ans2 = 0;
    ans2 = find(0, n - 1);
    sort(vec.begin(), vec.end(), cmp);
    long long width = 0;
    for(int i = 0; i < n; i++)
    {
        width += vec[i].first;
        ans1 = max(ans1, width * (long long) vec[i].second);
    }

    printf("%lld\n%lld\n", ans1, ans2);
    return 0;

}

/*
4
10 1 
6 15 
3  6 
9 10
*/