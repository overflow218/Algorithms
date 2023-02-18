#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int n, maximum = -1000000000, minimum = 1000000000;
vector<int> nums(11);
vector<int> oper(4, 0);

// chosen = 연산자 모아놓은것. 0은 더하기, 1은 빼기, 2는 곱하기, 3은 나누기
// Counter는 각 연살별 개수
void find(vector<int> &chosen, vector<int> &counter)
{
    // 연산자 다 고른 경우
    if(chosen.size() == n - 1)
    {
        deque<int> check(nums.begin(), nums.end());
        for(int i = 0; i < n - 1; i++)
        {
            int a = check.front();
            check.pop_front();
            int b = check.front();
            check.pop_front();

            int c;
            if(chosen[i] == 0)
            {
                c = a + b;
            } else if(chosen[i] == 1)
            {
                c = a - b;
            } else if(chosen[i] == 2)
            {
                c = a * b;
            } else 
            {
                c = a / b;
            }
            check.push_front(c);
        }
        maximum = max(maximum, check.front());
        minimum = min(minimum, check.front());
    } else 
    {
        for(int i = 0; i < 4; i++)
        {
            if(counter[i] < oper[i])
            {
                counter[i]++;
                chosen.push_back(i);
                find(chosen, counter);
                chosen.pop_back();
                counter[i]--;
            }
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cin >> oper[0] >> oper[1] >> oper[2] >> oper[3];

    vector<int> chosen; vector<int> counter(4, 0);
    find(chosen, counter);
    cout << maximum << '\n';
    cout << minimum << '\n';
    return 0;
}