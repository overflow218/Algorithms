#include <string>
#include <vector>
#include <queue>
using namespace std;

bool isVisited[101] = {false};
priority_queue<int> pq;

void visit(int current, int cnt, vector<int> &cards)
{
    if(isVisited[current])
    {
        pq.push(cnt);
        return;
    }
    isVisited[current] = true;
    visit(cards[current], cnt + 1, cards);
}
int solution(vector<int> cards) {
    cards.insert(cards.begin(), 0);
    for(int i = 1; i < cards.size(); i++)
    {
        if(!isVisited[cards[i]]) visit(cards[i], 0, cards);
    }

    int a = pq.top();
    pq.pop();
    if(!pq.empty())
    {
        int b = pq.top();
        pq.pop();    
        a *= b;
    } else 
    {
        return 0;
    }
    
    return a;
}