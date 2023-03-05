#include <iostream>
using namespace std;

int arr[110] = {0};
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int start = 0, end = n - 1;
    for(int it = 0; it < m - 1; it++)
    {
        int sum = 0, tmpSum = 0, nextStart = -1, nextEnd = -1;
        for(int i = start; i <= end; i++)
        {
            sum += arr[i];
        }

        int tmp = -987654321;
        for(int i = start; i < end; i++)
        {
            tmpSum += arr[i];
            int front = tmpSum;
            int back = sum - tmpSum;
            if(tmp < front && front > back)
            {
                tmp = front;
                nextStart = start;
                nextEnd = i;
            } 
            if(tmp < back && front < back)
            {
                tmp = back;
                nextStart = i + 1;
                nextEnd = end;
            }
        }

        start = nextStart;
        end = nextEnd;
    }

    int ans = 0;
    for(int i = start; i <= end; i++)
    {
        ans += arr[i];
    }

    cout << ans << '\n';
    return 0;
}

/*
5
3
1
1
3
6
-1
*/