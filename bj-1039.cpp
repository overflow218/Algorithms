#include <iostream>
#include <cmath>
#include <queue>
#include <set>
#include <string>
using namespace std;

int getJarisoo(int n)
{
    for(int i = 1; i <= 7; i++)
    {
        if(n < (int)pow(10, i)) return i;
    }
    return 0;
}

string swap(string s, int i, int j)
{
    char tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
    return s;
}

queue<string> q;
set<string> s;
int main()
{
    int n, m, k;
    scanf("%d %d", &n, &k);
    m = getJarisoo(n);

    int ans = -1;
    
    q.push(to_string(n));

    for(int cnt = 0; cnt < k; cnt++)
    {
        if(q.empty()) break;
        int limit = q.size();

        for(int it = 0; it < limit; it++)
        {
            string tmp = q.front();
            q.pop();
            for(int i = 0; i < m - 1; i++)
            {
                for(int j = i + 1; j < m; j++)
                {
                    if(i == 0 && tmp[j] == '0') continue;
                    s.insert(swap(tmp, i, j));
                }
            }
        }

        for(auto & it:s)
        {
            q.push(it);
        }
        s.clear();
    }

    while(!q.empty())
    {
        ans = max(stoi(q.front()), ans);
        q.pop();
    }

    printf("%d\n", ans);
    return 0;
}