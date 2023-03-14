#include <iostream>
#include <set>
using namespace std;

multiset<long long> candy;

int main()
{
    int n, a;
    long long b;
    cin >> n;
    for(int i = 0; i < n ;i++)
    {
        cin >> a >> b;
        if(a == 1)
        {
            candy.insert(b);
        } else if(a == 2)
        {
            // 단거 먹음
            if(b == 1 && !candy.empty())
            {
                auto it = --candy.end();
                candy.erase(it);
            }
            // 안단거 먹음
            if(b == -1 && !candy.empty())
            {
                auto it = candy.end()--;
                candy.erase(candy.begin());
            }
        } else 
        {
            if(candy.empty())
            {
                cout << "EMPTY ";
            } else 
            {
                // 단거 출력
                if(b == 1)
                {
                    cout << *candy.rbegin() << ' ';
                }
                // 안단거 출력
                if(b == -1)
                {
                    cout << *candy.begin() << ' ';
                }
            }
        }
    }
    cout <<'\n';
    return 0;
}

/*
9 
1 5 
1 2 
1 6 
2 1 
3 -1 
2 -1 
3 -1 
2 1 
3 -1
*/