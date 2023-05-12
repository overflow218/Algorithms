#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    while(storey > 0)
    {
        int tmp = storey % 10;
        int check = (storey / 10) % 10;
        answer += min(tmp, 10 - tmp);
        storey /= 10;
        if(tmp > 5 || (tmp == 5 && check >= 5)) storey++;
    }
    return answer;
}