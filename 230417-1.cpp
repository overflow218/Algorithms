#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

multiset<pair<int, int>> s;
int solution(vector<vector<int>> scores) {
    vector<pair<int, int>> vec;
    vector<int> check;
    int target = scores[0][0] + scores[0][1];
    // 완호 인센티브 못받는 경우 거르기
    for(int i = 0; i < scores.size(); i++)
    {
        if(scores[0][0] < scores[i][0] && scores[0][1] < scores[i][1]) return -1;
        vec.push_back(make_pair(scores[i][0], scores[i][1]));
    }
    
    // (x,y)에서 x기준으로 먼저 정렬해줌.
    sort(vec.begin(), vec.end());
    // 그러면 앞에있는 애들은 x는 작거나 같으니까 y까지 작아버리면 문제가 되는거임
    int idx = 0;
    while(idx < vec.size())
    {
        int a= vec[idx].first, b = vec[idx].second;
        vector<pair<int, int>> tmp = {make_pair(b, a)};
        idx++;
        while(idx < vec.size() && vec[idx].first == a)
        {
            tmp.push_back(make_pair(vec[idx].second, vec[idx].first));
            a = vec[idx].first; b = vec[idx].second;
            idx++;
        }

        while(!s.empty())
        {
            int b1 = s.begin() -> first, a1 = s.begin() -> second;
            // 하나라도 크거나 작은게 있으면 괜춘
            if(b1 >= b || a1 >= a) break;
            // 그게 아니면 얘는 제거
            s.erase(s.begin());
        }
        for(int i = 0; i < tmp.size(); i++)
        {
            s.insert(tmp[i]);
        }
    }

    // 유효한 애들만 데리고 순서를 메겨야함
    for(auto it = s.begin(); it != s.end(); it++)
    {
        check.push_back(it -> first + it -> second);
    }
    sort(check.begin(), check.end(), greater<int>());
    int ans = find(check.begin(), check.end(), target) - check.begin();
    return ans + 1;
}