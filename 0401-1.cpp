#include <string>
#include <vector>

using namespace std;

vector<int> stack;
int solution(vector<int> order)
{
    int answer = 0;
    int conveyIdx = 1, orderIdx = 0;
    while (conveyIdx <= order.size())
    {
        int target = order[orderIdx];
        // 순서 맞아서 그냥 넣으면 되는 경우
        if (conveyIdx == target)
        {
            answer++;
            conveyIdx++;
            orderIdx++;
            continue;
        }
        // 일단 스택에서 꺼낼 수 있는지 체크
        if (!stack.empty() && stack.back() == target)
        {
            stack.pop_back();
            answer++;
            orderIdx++;
            continue;
        }
        // 순서도 안맞고, 스택에서도 못꺼내면 일단 스택에 넣고 다음거를 살펴본다
        stack.push_back(conveyIdx);
        conveyIdx++;
    }

    while (!stack.empty())
    {
        if (stack.back() == order[orderIdx])
        {
            answer++;
            stack.pop_back();
            orderIdx++;
            continue;
        }
        break;
    }

    return answer;
}