#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValid[10001];
int main()
{
    int n, a, b, L, P;
    cin >> n ;
    vector<pair<int, int>> oilStation(n + 1);
    vector<int> leftOil(n + 1);
    vector<pair<int, int>> check;
    
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        oilStation[i] = make_pair(a, b);
    }
    cin >> L >> P;
    oilStation[n] = make_pair(L, 0);

    sort(oilStation.begin(), oilStation.end());
    int left = P;
    for(int i = 0; i <= n; i++)
    {
        int x = oilStation[i].first, avail = oilStation[i].second;
        isValid[i] = true;
        if(left < x)
        {
            cout << "-1\n";
            return 0;
        }
        
        if(i < n)
        {
            check.push_back(make_pair(avail, i));
        }
        
        leftOil[i] = left - x;
        left += avail;
    }

    // 여기까지 왔으면 일단 끝에 도달은 할 수 있단는 소리임.
    // 이제 넣을수 있는 양이 작은 주유소부터 안 멈춰도 된다면 안멈출거임.
    sort(check.begin(), check.end());

    int ans = n;
    for(int i = 0; i < n; i++)
    {
        int idx = check[i].second, amount = check[i].first;
        bool unneccesary = true;
        for(int j = idx + 1; j <= n; j++)
        {
            if(isValid[j] && leftOil[j] < amount)
            {
                unneccesary = false;
                break;
            }
        }

        if(unneccesary)
        {
            ans--;
            for(int j = idx + 1; j <= n; j++)
            {
                leftOil[j] -= amount;
            }
            isValid[idx] = false;
        }
    }

    cout << ans <<'\n';
    return 0;
}