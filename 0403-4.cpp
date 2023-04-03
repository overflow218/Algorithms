#include <string>
#include <vector>
#include <set>
using namespace std;
// (시작시간, 종료시간) 시작 기준으로 정렬때려놔야겠구먼

multiset<int> room;
multiset<pair<int, int>> q;

int calcul(string x)
{
    int hour = (x[0] - '0') * 10 + x[1] - '0';
    int minute = (x[3] - '0') * 10 + x[4] - '0';
    return hour * 60 + minute;
}
int solution(vector<vector<string>> book_time) {
    int answer = 0;
    for(int i = 0; i < book_time.size(); i++)
    {
        q.insert(make_pair(calcul(book_time[i][0]), calcul(book_time[i][1])));
    }
    
    while(!q.empty())
    {
        int start = q.begin() -> first, end = q.begin() -> second;
        q.erase(q.begin());
        while(!room.empty() && *room.begin() <= start)
        {
            room.erase(room.begin());
        }
        room.insert(end + 10);
        answer = max(answer, (int)room.size());
    }
    return answer;
}