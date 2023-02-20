#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(i <= n - 2 && vec[i] > vec[i + 1])
        {
            ans += 3 * (vec[i] - vec[i + 1]);
            vec[i] = vec[i + 1];
        }

        // 여기서부터는 무조건 vec[i] <= vec[i + 1]
        if(i <= n - 3)
        {
            if(vec[i + 1] > vec[i + 2]) 
            {
                int tmp = min(vec[i], vec[i + 1] - vec[i + 2]);
                ans += tmp * 5;
                vec[i] -= tmp;
                vec[i + 1] -= tmp;
            }

            if(vec[i + 1] <= vec[i + 2])
            {
                int tmp = min(vec[i], vec[i + 1]);
                ans += tmp * 7;
                vec[i] -= tmp;
                vec[i + 1] -= tmp;
                vec[i + 2] -= tmp;
            }
        }

        if(i <= n - 2)
        {
            int tmp = min(vec[i], vec[i + 1]);
            ans += tmp * 5;
            vec[i] -= tmp;
            vec[i + 1] -= tmp;
        }

        ans += vec[i] * 3;
        vec[i] = 0;
    }

    cout << ans << '\n';
    return 0;
}