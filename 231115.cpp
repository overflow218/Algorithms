/*
leetcode 1901번 문제

O(mlogn), O(nlogm)에 풀라는 조건 없었으면 그냥 m * n 순회했을듯.
일단 피크는 여러개가 존재할 수 있음. 문제는 어떤거든 peek를 하나 반환하라고 하고 있네
그러면 peek는 모든 줄에 존재하는걸까?
-> 예제만 봐도 모든 줄에 있는건 아니라는걸 알 수 있네

*/
class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int m, n;

    vector<int> check(int x, int y, vector<vector<int>>& mat)
    {
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx == m || ny < 0 || ny == n) continue;
            if(mat[nx][ny] > mat[x][y]) return check(nx, ny, mat);
        }
        return {x, y};
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        return check(0, 0, mat);
    }
};


/*
leetcode 1847번

단순히 생각해보면
n * k = 10억 -> 시간안에 절대 못들어옴
사이즈 순, id 크기로 정렬
일단 사이즈 맞는걸 O(logN)으로 찾을 수 있음
근데 사이즈 별로 roomId가 또 달라지니까 
근데 2개의 항목에 대해서 필터를 걸 수 있는 야무진 방법은 없나?
지금 방법은 뭔가 야무지진 않은데 말이쥐

와 대박... 
룸을 정렬하고 매번 쿼리를 날리면 어렵지만, 쿼리를 한번 정렬해놓으면
다음거는 무조건 현재거보다 뒤에 있는거니까 최적답을 그대로 찾아갈 수 있넹
*/

#include <set>
#include <algorithm>
using namespace std;

bool cmpRoom(vector<int> &v1, vector<int> &v2)
{
    return v1[1] > v2[1];
}

bool cmpQuery(vector<int> &v1, vector<int> &v2)
{
    return v1[1] > v2[1];
}

class Solution {
public:
    set<int> idSet;
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(), 0);
        for(int i = 0; i < queries.size(); i++)
        {
            queries[i].push_back(i);
        }
        sort(rooms.begin(), rooms.end(), cmpRoom);
        sort(queries.begin(), queries.end(), cmpQuery);

        int qIdx = 0;
        for(int i = 0; i < queries.size(); i++)
        {
            int pref = queries[i][0], minSize = queries[i][1], idx = queries[i][2];
            while(qIdx < rooms.size() && rooms[qIdx][1] >= minSize)
            {
                idSet.insert(rooms[qIdx++][0]);
            }

            if(idSet.empty())
            {
                ans[idx] = -1;
                continue;
            }

            auto it = idSet.lower_bound(pref);
            if(it == idSet.end())
            {
                ans[idx] = *idSet.rbegin();
                continue;
            }
            ans[idx] = *it;
            if(it != idSet.begin())
            {
                it--;
                if((pref - *it) <= ans[idx] - pref) ans[idx] = *it;
            }
        }
        return ans;
    }
};
