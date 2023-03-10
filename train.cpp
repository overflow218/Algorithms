#include <iostream>
#include <queue>
using namespace std;

int arr[250000];
int n, m;
// 현재까지 최솟값인 값의 인덱스
deque<int> dq;

int getIdx(int x)
{
    return x < n ? x : x - n;
}

int main()
{
    
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for(int i = 0; i < m - 1; i++)
    {
        while(!dq.empty() && arr[dq.back()] >= arr[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    for(int it = 0; it < n; it++)
    {
        int idx = m - 1 + it;

        while(!dq.empty() && arr[getIdx(dq.back())] >= arr[getIdx(idx)])
        {
            dq.pop_back();
        }
        dq.push_back(idx);
        printf("%d ", arr[getIdx(dq.front())]);

        if(dq.front() + m == idx + 1)
        {
            dq.pop_front();
        }
    }

    printf("\n");
    return 0;
}

/*
5 3
1 3 2 5 4
*/