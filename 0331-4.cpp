#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// 1번째 놓는 경우
int cache1[100001] = {0};
// 1번째 안놓는 경우
int cache2[100001] = {0};

int solution(vector<int> sticker)
{
    if(sticker.size() == 1) return sticker[0];
    cache1[0] = sticker[0];
    cache1[1] = sticker[0];
    cache2[1] = sticker[1];
    for(int i = 2; i < sticker.size(); i++)
    {
        cache1[i] = max(cache1[i - 1], cache1[i - 2] + sticker[i]);
        cache2[i] = max(cache2[i - 1], cache2[i - 2] + sticker[i]);
    }
    return max(cache1[sticker.size() - 2], cache2[sticker.size() - 1]);
}