#include <string>
#include <vector>

using namespace std;
vector<int> stack;

int solution(vector<int> order) {
    int answer = 0;
    int current = 1;
    for(int i = 0; i < order.size(); i++)
    {
        while(stack.empty() || stack.back() < order[i])
        {
            stack.push_back(current++);
        }

        if(stack.back() == order[i])
        {
            answer++;
            stack.pop_back();
        } else if(stack.back() > order[i])
        {
            break;
        }
    }
    return answer;
}
 