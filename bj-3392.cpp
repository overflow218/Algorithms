#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

// cX[i] = 변환된 x좌표 i에 해당되는 실제 x좌표의 값
vector<int> cX;
vector<int> cY;

set<int> originalX;
set<int> originalY;

// 원래좌표 -> 변환 좌표로 가는 맵핑
unordered_map<int, int> Xmap;
unordered_map<int, int> Ymap;
vector<vector<int>> vec;

int poster[10010][1010] = {0};
int main()
{
    int n, x1, x2, y1, y2;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        originalX.insert(x1);
        originalX.insert(x2);
        originalY.insert(y1);
        originalY.insert(y2);
        vec.push_back({x1, y1, x2, y2});
    }

    // 좌표 변환해주기
    int xIdx = 0, yIdx = 0;
    while (!originalX.empty())
    {
        Xmap[*originalX.begin()] = cX.size();
        cX.push_back(*originalX.begin());
        originalX.erase(originalX.begin());
    }

    while (!originalY.empty())
    {
        Ymap[*originalY.begin()] = cY.size();
        cY.push_back(*originalY.begin());
        originalY.erase(originalY.begin());
    }

    // 변환한 캔버스위에 표시해주기 -> 오늘 나왔던 부분합 배열 활용
    for (int i = 0; i < vec.size(); i++)
    {
        // {x1, x2, y1, y2} 가 담겨있는 배열임.
        x1 = Xmap[vec[i][0]];
        y1 = Ymap[vec[i][1]];
        x2 = Xmap[vec[i][2]];
        y2 = Ymap[vec[i][3]];
        poster[x1][y1]++;
        poster[x1][y2]--;
        poster[x2][y1]--;
        poster[x2][y2]++;
    }

    // 이제 전체 부분합 계산해주고 실제 영역으로 바꿔서 넓이 구해주면 됨.
    int h = cX.size(), w = cY.size();
    long long ans = 0;
    if (poster[0][0] > 0)
    {
        ans += (long long)(cX[1] - cX[0]) * (long long)(cY[1] - cY[0]);
    }
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (i == 0 && j == 0)
                continue;
            if (i == 0)
                poster[i][j] += poster[i][j - 1];
            if (j == 0)
                poster[i][j] += poster[i - 1][j];
            if (i > 0 && j > 0)
                poster[i][j] += poster[i - 1][j] + poster[i][j - 1] - poster[i - 1][j - 1];
            if (poster[i][j] > 0)
            {
                ans += (long long)(cX[i + 1] - cX[i]) * (long long)(cY[j + 1] - cY[j]);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
