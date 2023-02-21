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
    if(a.start != b.start) return a.start < b.start;
    return a.end < b.end;
}

// a가 b를 포함하면 1, 포함은 안해도 만나긴 하면 0, 만나지도 않으면 -1
// a의 시작이 무조건 b보다 작거나 같음
int check(bus &a, bus &b)
{
    int s1 = a.start, e1 = a.end, s2 = b.start, e2 = b.end;

    if(e1 <= s2) return -1;
    if(e2 <= e1) return 1;
    return 0;
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
    for(int i = 0; i < limit; i++)
    {
        int busNumer = busLine[i].number;
        if(isDeleted[busNumer]) continue;

        for(int j = i + 1; j < limit; j++)
        {
            int nextNumber = busLine[j].number;
            if(isDeleted[nextNumber]) continue;
            int code = check(busLine[i], busLine[j]);
            
            // 안겹치면 종료
            if(code == -1) break;
            // i 버스 노선에 j 버스 노선이 포함됨
            if(code == 1)
            {
                isDeleted[nextNumber] = true;
            }
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