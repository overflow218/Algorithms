#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int arr[101][101] = {0};
int ROW = 3, COL = 3;

void Roper()
{
    int nextC = COL;
    for(int i = 1; i <= ROW; i++)
    {
        vector<int> cnt(101, 0);
        vector<pair<int, int>> tmp;
        set<int> s;
        for(int j = 1; j <= COL; j++)
        {
            if(arr[i][j] > 0)
            {
                cnt[arr[i][j]]++;
                s.insert(arr[i][j]);
            }
        }

        for(const int &x:s)
        {
            tmp.push_back(make_pair(cnt[x], x));
        }
        sort(tmp.begin(), tmp.end());
        nextC = max(nextC, 2 * (int)tmp.size());

        int idx = 1;
        for(const auto &p:tmp)
        {
            int a = p.first, num = p.second;
            arr[i][idx] = num; arr[i][idx + 1] = a;
            idx += 2;
            if(idx > 100) break;
        }

        for(int j = idx; j <= 100; j++)
        {
            arr[i][j] = 0;
        }
    }
    nextC = min(nextC, 100);
    COL = nextC;
}

void Coper()
{
    int nextR = ROW;
    for(int col = 1; col <= COL; col++)
    {
        vector<int> cnt(101, 0);
        vector<pair<int, int>> tmp;
        set<int> s;
        for(int row = 1; row <= ROW; row++)
        {
            if(arr[row][col] > 0)
            {
                cnt[arr[row][col]]++;
                s.insert(arr[row][col]);
            }
        }

        for(const int &x:s)
        {
            tmp.push_back(make_pair(cnt[x], x));
        }
        sort(tmp.begin(), tmp.end());
        nextR = max(nextR, 2 * (int)tmp.size());

        int idx = 1;
        for(const auto &p:tmp)
        {
            int a = p.first, num = p.second;
            arr[idx][col] = num; arr[idx + 1][col] = a;
            idx += 2;
            if(idx > 100) break;
        }
        for(int row = idx; row <= 100; row++)
        {
            arr[row][col] = 0;
        }
    }
    nextR = min(nextR, 100);
    ROW = nextR;
}

int main()
{
    int r, c, k;
    cin >> r >> c >> k;
    int time = 0;

    for(int i = 1; i <= 3; i++)
    {
        for(int j = 1; j <= 3; j++)
        {
            cin >> arr[i][j];
        }
    }

    while(time <= 100)
    {
        if(arr[r][c] == k)
        {
            cout << time << '\n';
            return 0;
        }
        // R 연산
        if(ROW >= COL)
        {
            Roper();
        } 
        // C 연산
        else {
            Coper();
        }
        time++;
    }
    cout << "-1\n";
    return 0;
}