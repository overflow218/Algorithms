#include <string>
#include <vector>
#include <set>
using namespace std;

set<pair<int, int>> s;
vector<int> solution(vector<int> numbers) {
    int n = numbers.size();
    vector<int> answer(n, -1);
    for(int i = 0; i < numbers.size(); i++)
    {
        auto it = s.lower_bound(make_pair(numbers[i], 0));
        while(s.begin() != it)
        {
            answer[(*s.begin()).second] = numbers[i];
            s.erase(s.begin());
        }
        s.insert(make_pair(numbers[i], i));
    }
    return answer;
}