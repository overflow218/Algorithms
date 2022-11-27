#include <string>
#include <vector>
#include <set>
using namespace std;

multiset<int> scoreSet;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    for(int i = 0; i < score.size(); i++)
    {
        if(i < k)
        {
            scoreSet.insert(score[i]);
        } else 
        {
            if(score[i] > *scoreSet.begin())
            {
                scoreSet.erase(scoreSet.begin());
                scoreSet.insert(score[i]);
            }
        }
        answer.push_back(*scoreSet.begin());
    }
    return answer;
}
