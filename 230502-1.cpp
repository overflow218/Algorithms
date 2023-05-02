#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    for(const auto ball: balls)
    {
        int x = ball[0], y = ball[1];
        int tmp = 3000000;
        if(startX < x || startY != y) tmp = min(tmp, (int)pow(x + startX, 2) + (int)pow(abs(y - startY), 2));
        if(startX > x || startY != y) tmp = min(tmp, (int)pow(2 * m - x - startX, 2) + (int)pow(abs(y - startY), 2));
        if(startY < y || startX != x) tmp = min(tmp, (int)pow(abs(x - startX), 2) + (int)pow(y + startY, 2));
        if(startY > y || startX != x) tmp = min(tmp, (int)pow(abs(x - startX), 2) + (int)pow(2 * n - y - startY, 2));
        
        answer.push_back(tmp);             
    }
    return answer;
}