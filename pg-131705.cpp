#include <string>
#include <vector>

using namespace std;
int answer = 0;

void find(int idx, vector<int> &chosen, vector<int> &number)
{
    if(chosen.size() == 3)
    {
        int cnt = number[chosen[0]] + number[chosen[1]] + number[chosen[2]];
        if(cnt == 0) answer++;
    } else if(idx >= number.size())
    {
        return;
    } else 
    {
        for(int i = idx; i < number.size(); i++)
        {
            chosen.push_back(i);
            find(i + 1, chosen, number);
            chosen.pop_back();
        }
    }
}
int solution(vector<int> number) {
    vector<int> chosen;
    find(0, chosen, number);
    return answer;
}