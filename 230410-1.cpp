#include <string>
#include <vector>

using namespace std;

vector<int> p1;
vector<int> p2;
long long solution(vector<int> sequence) {
    long long answer = -50000000000;
    
    for(int i = 0; i < sequence.size(); i++)
    {
        if(i % 2 == 0)
        {
            p1.push_back(sequence[i]);
            p2.push_back(-sequence[i]);
        }
        if(i % 2 != 0)
        {
            p1.push_back(-sequence[i]);
            p2.push_back(sequence[i]);
        }
    }
    
    int n = sequence.size();
    long long s1 = 0, s2 = 0;
    
    for(int i = 0; i < n; i++)
    {
        if(s1 > 0)
        {
            s1 += p1[i];
        }
        if(s1 <= 0)
        {
            s1 = p1[i];
        } 
        if(s2 > 0)
        {
            s2 += p2[i];
        }
        if(s2 <= 0)
        {
            s2 = p2[i];
        } 
        answer = max(answer, s1);
        answer = max(answer, s2);
    }
    return answer;
}