#include <string>
#include <vector>
#include <set>
using namespace std;

multiset<int> s;
int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    for(int i = 0; i < B.size(); i++)
    {
        s.insert(B[i]);
    }
    
    for(int i = 0; i < A.size(); i++)
    {
        auto it = s.upper_bound(A[i]);
        if(it != s.end())
        {
            answer++;
            s.erase(it);
        }
    }
    return answer;
}