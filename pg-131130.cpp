#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isVisited[101] = {0};
vector<int> vec;

void find(int idx, int cnt, vector<int> & cards)
{
    if(isVisited[idx])
    {
        vec.push_back(cnt);
    } else 
    {
        isVisited[idx] = true;
        find(cards[idx - 1], cnt + 1, cards);
    }
}

int solution(vector<int> cards) {
    for(int i = 1; i <= cards.size(); i++)
    {
        if(!isVisited[i])
        {
            find(i, 0, cards);
        }
    }
    sort(vec.begin(), vec.end(), greater());
    return vec.size() == 1 ? 0 : vec[0] * vec[1];
}