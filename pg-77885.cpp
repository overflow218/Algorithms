#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(int i = 0; i < numbers.size(); i++)
    {
        if(numbers[i] % 2 == 0)
        {
            answer.push_back(numbers[i] + 1);
        } 
        else 
        {
            /*
            홀수일때는 직접 찾아가야함. 
            계속 애먹었던 이유. 기본적으로 1, 2 이렇게 literal로 쓰면 자동으로 32 bit int로 들어가버림
            원래 자료형 안쓰면 더 큰거 따라가는걸로 알고 있는데 비트 연산자일때는 int로 따라가버리는것같음
            그래서 long long 의 경우 상위 32비트는 버려져서 자꾸 오답이 생기는거였음. 
            long long, 1ll로 바꾸니까 문제 해결됨
            */
            
            for(long long idx = 0; idx < 64; idx++)
            {
                if(!(numbers[i] & (1ll << idx)))
                {   
                    answer.push_back(numbers[i] + (1ll << idx) - (1ll << (idx - 1ll)));
                    break;
                }
            }
        }
    }

    return answer;
}