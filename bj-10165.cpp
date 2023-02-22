#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct bus {
    int start;
    int end;
    int number;
};

int n, m;
vector<bus> busLine;
bool isDeleted[500001] = {false};

bool cmp(bus a, bus b)
{
    if(a.end != b.end) return a.end < b.end;
    return a.start < b.start;
}

int main()
{
    int a, b;
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        // 정방향일때
        if(a < b)
        {
            bus newBus1 = {a, b, i};
            bus newBus2 = {a + n, b + n, i};
            busLine.push_back(newBus1);
            busLine.push_back(newBus2);
        } else 
        {
            // 역방향
            bus newBus1 = {a, b + n, i};
            busLine.push_back(newBus1);
        }
    }

    sort(busLine.begin(), busLine.end(), cmp);

    int limit = busLine.size();
    bus minimum = busLine[limit - 1];
    for(int i = limit - 2; i >= 0; i--)
    {
        
        int s = busLine[i].start, e = busLine[i].end, number = busLine[i].number;

        // i번째 노선에 현재 minimum이 포함됨. 
        if(e == minimum.end)
        {
            isDeleted[minimum.number] = true;
            minimum = busLine[i];
        } 
        // 현재 minimum에 i번째 노선이 포함됨
        else if(minimum.start <= s)
        {  
            isDeleted[number] = true;
        } 
        // 위의 두가지 경우가 아니라면 minimum을 새롭게 갱신해준다.
        else 
        {
            minimum = busLine[i];
        }
    }

    for(int i = 1; i <= m; i++)
    {
        if(!isDeleted[i])
        {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}