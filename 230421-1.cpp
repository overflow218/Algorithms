#include <string>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
/*
결국에는 약수의 개수를 구해야하는 문제인데
찾아야하는 원소 개수가 최대 10만개이고, 범위가 5백만이구만
약수의 개수는 소인수분해를 해야하는데 소인수분해가 빡셀텐뎅
*/

int counter[5000001] = {0};
int check[5000001] = {0};
vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;
    int limit = sqrt(e);
    for(int i = 1; i <= e; i++)
    {
        for(int j = i; j <= e; j += i) counter[j]++;
    }
    check[e] = e;
    for(int i = e - 1; i >= 1; i--)
    {
        if(counter[i] >= counter[i + 1]) check[i] = i;
        if(counter[i] < counter[i + 1])
        {
            check[i] = check[i + 1];
            counter[i] = counter[i + 1];
        }
    }
    
    for(int i = 0; i < starts.size(); i++)
    {
        answer.push_back(check[starts[i]]);
    }
    return answer;
}