#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

bool isVisited[100001] = {0};
priority_queue<pair<int, int>> pq;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    pq.push(make_pair(0, n));
    while(!pq.empty())
    {
        pair<int, int> current = pq.top();
        int score = -current.first;
        int position = current.second;
        pq.pop();
        // 이미 방문했거나 범위 벗어나는 경우 컷
        if(position < 0 || position > 100000 || isVisited[position]) continue;
        isVisited[position] = true;
        if(position == k){
            printf("%d\n", score);
            break;
        }
        if(position > k)
        {
            pq.push(make_pair(-(score + 1), position - 1));
        } else 
        {
            pq.push(make_pair(-(score + 1), position + 1));
            pq.push(make_pair(-(score + 1), position - 1));
            pq.push(make_pair(-score, position * 2));
        }
    }
    return 0;
}