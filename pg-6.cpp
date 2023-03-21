#include <string>
#include <vector>
#include <set>
using namespace std;

set<int> check;

bool isSame(string s1, string s2)
{
    if(s1.size() != s2.size()) return false;
    for (int i = 0; i < s1.size(); i++)
    {
        if(s1[i] != s2[i] && s2[i] != '*') return false;
    }
    return true;
}

void find(int idx, int checkSum, vector<string> &user_id, vector<string> &banned_id)
{
    if(idx == banned_id.size())
    {
        check.insert(checkSum);
        return;
    }
    
    for(int i = 0; i < user_id.size(); i++)
    {
        if(checkSum & (1 << i)) continue;
        if(isSame(user_id[i], banned_id[idx]))
        {
            find(idx + 1, checkSum + (1 << i), user_id, banned_id);
        }
    }
}
int solution(vector<string> user_id, vector<string> banned_id) {
    find(0, 0, user_id, banned_id);
    return check.size();
}