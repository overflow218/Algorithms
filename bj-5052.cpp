#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t, n;
    char tmp[20];
    cin >> t;
    for(int it = 0; it < t; it++)
    {
        cin >> n;
        vector<string> phone;
        for(int i = 0; i < n; i++)
        {
            scanf("%s", tmp);
            string x = tmp;
            phone.push_back(x);
        }
        sort(phone.begin(), phone.end());
        bool isConsistent = true;
        for(int i = 0; i < n - 1; i++)
        {
            if(phone[i] == phone[i + 1].substr(0, phone[i].size()))
            {
                isConsistent = false;
                break;
            }
        }
        string ans = isConsistent ? "YES\n" : "NO\n";
        cout << ans;
    }

    return 0;
}