#include <iostream>
#include <vector>
using namespace std;

struct Point{
    int x1;
    int x2;
    int y1;
    int y2;
};

bool isOverlapped = false;

long long getArea(Point &p)
{
    return (long long)(p.x2 - p.x1) * (long long)(p.y2 - p.y1);
}

Point overlap(Point &p1, Point &p2)
{
    isOverlapped = false;
    if(p1.x1 <= p2.x1 && p2.x1 <= p1.x2)
    {
        if(p1.y1 <= p2.y1 && p2.y1 <= p1.y2)
        {
            isOverlapped = true;
            Point overlapped = {p2.x1, min(p2.x2, p1.x2), p2.y1, min(p2.y2, p1.y2)};
            return overlapped;
        } else if(p2.y1 <= p1.y1 && p1.y1 <= p2.y2)
        {
            isOverlapped = true;
            Point overlapped = {p2.x1, min(p2.x2, p1.x2), p1.y1, min(p2.y2, p1.y2)};
            return overlapped;
        }
    }

    if(p2.x1 <= p1.x1 && p1.x1 <= p2.x2)
    {
        if(p2.y1 <= p1.y1 && p1.y1 <= p2.y2)
        {
            isOverlapped = true;
            Point overlapped = {p1.x1, min(p2.x2, p1.x2), p1.y1, min(p2.y2, p1.y2)};
            return overlapped;
        } else if(p1.y1 <= p2.y1 && p2.y1 <= p1.y2)
        {
            isOverlapped = true;
            Point overlapped = {p1.x1, min(p2.x2, p1.x2), p2.y1, min(p2.y2, p1.y2)};
            return overlapped;
        }
    }
    return Point();
}

vector<vector<Point>> checker(2001);
int main()
{
    int n, x1, x2, y1, y2;
    cin >> n;

    for(int it = 0; it < n; it++)
    {
        cin >> x1 >> x2 >> y1 >> y2;
        Point newPoint = {x1, x2, y1, y2};

       int stage = 0;
       int counter[2001] = {0};
       while(stage < n)
       {
            // 겹치는게 없어서 넘어가도 되면 참, 겹치는게 있어서 다음 단계도 확인해야하면 거짓
            bool isDone = true;
            int limit = (int)checker[stage].size() - counter[stage];
            for(int i = 0; i < limit; i++)
            {
                Point tmp = overlap(newPoint, checker[stage][i]);
                if(isOverlapped)
                {
                    isDone = false;
                    checker[stage + 1].push_back(tmp);
                    counter[stage + 1]++;
                }
            }
            if(isDone)
            {
                break;
            }
            stage++;
       }
       checker[0].push_back(newPoint);
    } 

    long long ans = 0;

    // 실제 답 계산하기
    for(int i = 0; i <= n; i++)
    {
        if(checker[i].empty()) continue;

        for(int j = 0; j < checker[i].size(); j++)
        {
            long long tmpArea = getArea(checker[i][j]);
            if(i % 2 == 0)
            {
                ans += tmpArea;
            } else 
            {
                ans -= tmpArea;
            }
        }
    }

    printf("%lld\n", ans);
    return 0;
}

/*
4
0 1 0 10
0 10 0 1
0 10 9 10
9 10 0 10

5
0 2 0 2
0 1 0 1
1 2 0 1
0 1 1 2
1 2 1 2
*/