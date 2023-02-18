#include <iostream>
#include <vector>
using namespace std;

int n, ans = 987654321;
int arr[20][20];

void find(int idx, int cnt, vector<bool> &isChosen)
{
    // 절반 다 나눴을때
    if(cnt == n / 2)
    {
        vector<int> team1;
        vector<int> team2;
        int p1 = 0, p2 = 0;
        for(int i = 0; i < n; i++)
        {
            if(isChosen[i])
            {
                team1.push_back(i);
            } else 
            {
                team2.push_back(i);
            }
        }

        for(int i = 0; i < n/2; i++)
        {
            for(int j = i + 1; j < n/2; j++)
            {
                p1 += arr[team1[i]][team1[j]] + arr[team1[j]][team1[i]];
                p2 += arr[team2[i]][team2[j]] + arr[team2[j]][team2[i]];
            }
        }
        ans = min(ans, abs(p1 - p2));
    } else if(idx == n)
    {
        return;
    } else {
        isChosen[idx] = true;
        find(idx + 1, cnt + 1, isChosen);
        isChosen[idx] = false;
        find(idx + 1, cnt, isChosen);
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    vector<bool> isChosen(n, false);
    find(0, 0, isChosen);
    cout << ans << '\n';
    return 0;
}