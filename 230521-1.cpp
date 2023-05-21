#include <vector>
#include <algorithm>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int getDist(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

bool isGoodToGo(vector<pair<int, int>>& pairs, int x, int y, int d)
{
    for(int i = 0; i < pairs.size(); i++)
    {
        if(getDist(x, y, pairs[i].first, pairs[i].second) < d) return false;
    }
    return true;
}

int solution(int n, int m, vector<vector<int>> timetable) {
    vector<int> startTime;
    vector<int> endTime;
    for(int i = 0; i < timetable.size(); i++)
    {
        startTime.push_back(timetable[i][0]);
        endTime.push_back(timetable[i][1]);
    }
    sort(startTime.begin(), startTime.end());
    sort(endTime.begin(), endTime.end());
    int sIdx = 0, eIdx = 0;
    int maxCustomer = 0;
    int tmpCustomer = 0;
    while(sIdx < m || eIdx < m)
    {
        int s = sIdx < m ? startTime[sIdx] : 987654321;
        int e = eIdx < m ? endTime[eIdx] : 987654321;
        int tmp = min(s, e);
        while(sIdx < m && startTime[sIdx] <= tmp)
        {
            tmpCustomer++;
            sIdx++;
        }
        maxCustomer = max(maxCustomer, tmpCustomer);
        while(eIdx < m && endTime[eIdx] <= tmp)
        {
            tmpCustomer--;
            eIdx++;
        }
    }
    if(maxCustomer <= 1) return 0;
    for(int d = 2 * n - 2; d >= 1; d--)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                vector<pair<int, int>> points = {make_pair(i, j)};
                for(int x = i; x < n; x++)
                {
                    for(int y = 0; y < n; y++)
                    {
                        if(x == i && y == j) continue;
                        if(isGoodToGo(points, x, y, d)) points.push_back(make_pair(x, y));
                        if(points.size() == maxCustomer)
                        {
                            for(int k = 0; k < points.size(); k++) return d;
                        }
                    }
                }
                
            }
        }
    }
    return 0;
}