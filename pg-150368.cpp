#include <string>
#include <vector>

using namespace std;
int customer = 0, amount = 0;
int rate[] = {90, 80, 70, 60};
void find(int idx, vector<vector<int>>& users, vector<int>& emoticons, vector<int>& discount)
{
    // 할인율 다 구했을때
    if(idx == emoticons.size())
    {
        int tmp_customer = 0, tmp_amount = 0;
        for(auto &user: users)
        {
            int discount_rate = 100 - user[0];
            int register_amount = user[1];
            int paid_amount = 0;
            for(int i = 0; i < emoticons.size(); i++)
            {
                if(discount_rate >= discount[i])
                {
                    int new_price = emoticons[i] / 100 * discount[i];
                    paid_amount += new_price;
                }
            }
            if(paid_amount >= register_amount)
            {
                tmp_customer++;
            } else 
            {
                tmp_amount += paid_amount;
            }
        }
        if(tmp_customer > customer)
        {
            customer = tmp_customer;
            amount = tmp_amount;
        } else if(tmp_customer == customer)
        {
            amount = max(amount, tmp_amount);
        }
    } else 
    {
        for(int i = 0; i < 4; i++)
        {
            discount.push_back(rate[i]);
            find(idx + 1, users, emoticons, discount);
            discount.pop_back();
        }
    }
}
vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    vector<int> discount;
    find(0, users, emoticons, discount);
    answer.push_back(customer);
    answer.push_back(amount);
    return answer;
}