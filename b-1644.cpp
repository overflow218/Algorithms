#include <iostream>
#include <vector>
#include <deque>
using namespace std;

bool skip[4000001] = {false};
int main()
{
    int n;
    vector<int> prime;
    scanf("%d", &n);
    for(int i = 2; i <= n; i++)
    {
        if(skip[i]) continue;
        prime.push_back(i);
        for(int j = 2; j * i <= n; j++)
        {
            skip[i * j] = true;
        }
    }

    int idx = 0, sum = 0, cnt = 0;
    deque<int> q;
    while(idx < prime.size())
    {
        // printf("idx: %d, sum: %d\n", idx, sum);
        if(sum < n)
        {
            q.push_back(prime[idx]);
            sum += prime[idx++];
        }
        while(sum > n)
        {
            sum -= q.front();
            q.pop_front();
        }
        if(sum == n){
            cnt++;
            sum -= q.front();
            q.pop_front();
        }
    }
    printf("%d\n", cnt);
    return 0;
}