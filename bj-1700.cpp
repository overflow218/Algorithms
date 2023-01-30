#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, k;
    vector<bool> isOn(101, false);
    vector<int> plug(101);
    queue<int> next[101];
    priority_queue<pair<int, int>> pq;
    scanf("%d %d", &n, &k);
    int ans = 0, cnt = 0;
    for(int i = 0; i < k; i++)
    {
        scanf("%d", &plug[i]);
        next[plug[i]].push(i);
    }

    for(int i = 0; i < k; i++)
    {
        if(!isOn[plug[i]])
        {
            // 아직 자리 있을때 그냥 꽂음
            if(cnt < n)
            {
                cnt++;
            } else // 기존껄 뽑아야하는 경우 -> 다음 사용이 제일 오래 남은애를 뽑음
            {
                int popped = pq.top().second;
                pq.pop();
                isOn[popped] = false;
                ans++;
            }
        }

        isOn[plug[i]] = true;
        next[plug[i]].pop();
        int nextOccur = next[plug[i]].empty() ? 1000 : next[plug[i]].front();
        pq.push(make_pair(nextOccur, plug[i]));   
    }
    printf("%d\n", ans);
    return 0;
}