#include <string>
#include <vector>

using namespace std;

int member = 0, sell = 0;

void find(vector<vector<int>> &users, vector<int> &emoticons, vector<int> &chosen)
{
    // 계산해주면 됨
    if(chosen.size() == emoticons.size())
    {
        int emoticonPlus = 0, total = 0;
        for(const auto& ho: users)
        {
            int rate = ho[0], limit = ho[1], amount = 0;
            for(int j = 0; j < emoticons.size(); j++)
            {
                // 이때는 구매함
                if(chosen[j] >= rate)
                {
                    amount += emoticons[j] * (100 - chosen[j]) / 100;
                }
            }
            if(amount >= limit)
            {
                emoticonPlus++;
            } else 
            {
                total += amount;
            }
        }
        if(emoticonPlus > member)
        {
            member = emoticonPlus;
            sell = total;
        } else if(emoticonPlus == member)
        {
            sell = max(sell, total);
        }
    } else 
    {
        for(int i = 1; i <= 4; i++)
        {
            chosen.push_back(10 * i);
            find(users, emoticons, chosen);
            chosen.pop_back();
        }
    }
}
vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    
    vector<int> chosen;
    find(users, emoticons, chosen);
    
    answer.push_back(member);
    answer.push_back(sell);
    return answer;
}