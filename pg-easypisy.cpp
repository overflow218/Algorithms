#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    int limit = number.size();
    for(int i = 0; i < limit; i++)
    {
        for(int j = i + 1; j < limit; j++)
        {
            for(int k = j + 1; k < limit; k++)
            {
                if(number[i] + number[j] + number[k] == 0)
                {
                    answer++;
                }
            }
        }
    }
    return answer;
}