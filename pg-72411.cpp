#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 나왔으면 true, 아니면 false
bool alphaBet[26] = {false};
// 나온 단품 메뉴들 숫자로 담고 있음. A = 0, B = 1, ... X = 25. 총 단품 메뉴의 개수라고 할 수 있음. 
vector<int> menu;
// 손님별 주문내역 숫자로 변환한것.
vector<int> order; 
// 정답
vector<string> answer;
// 2명이상 시켜서 가능은 한데 개수를 비교해봐야하는 경우
vector<string> candidate;
int orderCount = 0;

// 현재 idx번 확인, 최대 limit개 선택, chosen은 현재까지 고른 메뉴들
void find(int idx, int limit, vector<int> &chosen)
{
    // 메뉴 다 고른 경우
    if(chosen.size() == limit)
    {
        // 유효성 검사.
        int tmpMenu = 0;
        for(int i = 0; i < limit; i++)
        {
            tmpMenu += 1 << (menu[chosen[i]]);
        }
        int cnt = 0;
        // 주문건수가 2번 이상인지 확인.
        for(int i = 0; i < order.size(); i++)
        {
            if((order[i] & tmpMenu) == tmpMenu) cnt++;
        }
        if(cnt >= 2 && cnt >= orderCount)
        {
            if(cnt > orderCount)
            {
                orderCount = cnt;
                candidate.clear();
            }
            string ans = "";
            for(int i = 0; i < limit; i++)
            {
                ans += menu[chosen[i]] + 'A';
            }
            candidate.push_back(ans);
        }
        return;
    }
    if(idx == menu.size()) return;
    // idx번 넣고 가는경우
    chosen.push_back(idx);
    find(idx + 1, limit, chosen);
    chosen.pop_back();
    // idx번 안넣고 가는경우
    find(idx + 1, limit, chosen);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    for(int i = 0; i < orders.size(); i++)
    {
        int tmp = 0;
        for(int j = 0; j < orders[i].size(); j++)
        {
            alphaBet[orders[i][j] - 'A'] = true;
            tmp += 1 << (orders[i][j] - 'A');
        }
        order.push_back(tmp);
    }

    for(int i = 0; i < 26; i++)
    {
        if(alphaBet[i])
        {
            menu.push_back(i);
        }
    }

    int n = menu.size();

    for(int i = 0; i < course.size(); i++)
    {
        vector<int> vec;
        orderCount = 0;
        candidate.clear();
        find(0, course[i], vec);
        for(int j = 0; j < candidate.size(); j++)
        {
            answer.push_back(candidate[j]);
        }
    }

    sort(answer.begin(), answer.end());
    return answer;
}