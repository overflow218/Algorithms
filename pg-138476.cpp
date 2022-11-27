#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<int, int> farm;
vector<int> order;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    for(int i = 0; i < tangerine.size(); i++)
    {
        farm[tangerine[i]]++;
    }

    map<int, int> :: iterator it;
    for(it = farm.begin(); it != farm.end(); it++)
    {
        order.push_back(it -> second);
    }

    sort(order.begin(), order.end(), greater());
    int total = 0;
    for(int i = 0; i < order.size(); i++)
    {
        total += order[i];
        answer++;
        if(total >= k)
        {
            break;
        }
    }
    return answer;
}
