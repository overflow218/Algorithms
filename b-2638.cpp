#include <iostream>
#include <vector>
#include <deque>
using namespace std;


int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    vector<vector<int>> arr;
    deque<pair<int, int>> cheese;

    for(int i = 0; i < n; i++)
    {
        vector<int> vec(m);
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &vec[j]);
            if(vec[j] == 1)
            {
                cheese.push_back(make_pair(i, j));
            }
        }
        arr.push_back(vec);
    }
    
    int cheeseCount = cheese.size();
    int ans = 0;
    while(cheeseCount > 0)
    {
        ans++;
        vector<pair<int, int>> melting;
        
        for(int i = 0; i < cheese.size(); i++)
        {
            pair<int, int> cur = cheese.front();
            cheese.pop_front();
            int x = cur.first, y = cur.second;
            
        }


    }


    return ans;
}