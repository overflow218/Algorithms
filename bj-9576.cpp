#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t, n, m, a, b;
    scanf("%d", &t);
    for(int test = 0; test < t; test++)
    {
        scanf("%d %d", &n, &m);
        set<int> book;
        vector<pair<int, int>> students(m);
        for(int i = 1; i <= n; i++)
        {
            book.insert(-i);
        }
        for(int i = 0; i < m; i++)
        {
            scanf("%d %d", &a, &b);
            students[i] = make_pair(a, b);
        }
        sort(students.begin(), students.end());
        int ans = 0;
        for(int i = m - 1; i >= 0; i--)
        {
            int begin = students[i].first, end = students[i].second;
            auto it = book.lower_bound(-end);
            if(it != book.end() && *it <= -begin)
            {
                ans++;
                book.erase(it);
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}

/*
2
100 4
1 7
2 7 
3 8 
2 5
8 3
8 8 
7 7 
6 8
*/