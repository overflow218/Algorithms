#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// player[i] = i번 선수의 공 색깔, 크기 
int player[200000][2];
// (크기, 색깔)
vector<pair<int, int>> balls;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, c, s;
    cin >> n;
    // 공 색깔, 색깔별 크기 
    vector<vector<int>> ballColor(n + 1);
    // 공 색깔, 색깔별 크기 기준 부분합
    vector<vector<int>> colorPsum(n + 1);
    // 공 크기별로 정렬한것의 부분합. 
    vector<int> ballPsum;
    for(int i = 0; i < n; i++)
    {
        cin >> c >> s;
        player[i][0] = c; player[i][1] = s;
        balls.push_back(make_pair(s, c));
    }
    sort(balls.begin(), balls.end());

    for(const auto& ball: balls)
    {
        c = ball.second; s = ball.first;
        ballColor[c].push_back(s);
        int pSum = colorPsum[c].empty() ? s : colorPsum[c].back() + s;
        colorPsum[c].push_back(pSum);
        if(ballPsum.empty())
        {
            ballPsum.push_back(s);
        } else 
        {
            ballPsum.push_back(s + ballPsum.back());
        }
    }

    for(int i = 0; i < n; i++)
    {
        c = player[i][0]; s = player[i][1];
        int sizeIdx = lower_bound(balls.begin(), balls.end(), make_pair(s, 0)) - balls.begin();
        int bSum = sizeIdx == 0 ? 0 : ballPsum[sizeIdx - 1];
        int colorIdx = lower_bound(ballColor[c].begin(), ballColor[c].end(), s) - ballColor[c].begin();
        int cSum = colorIdx == 0 ? 0 : colorPsum[c][colorIdx - 1];
        cout << bSum - cSum << '\n';
    }

    return 0;
}