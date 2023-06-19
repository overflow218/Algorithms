/*
어차피 다해보는거 아니면 예측을 하기 어려운 상황임. 
전체 8개 밖에 안되니까 8! 하면은 4만개 정도밖에 안되니까 그냥 다 계산해보면 됨. 
*/
class Solution {
public:
    int ans = 0;
    void find(vector<int> &chosen, vector<bool>& isChosen,vector<vector<int>>& students, vector<vector<int>>& mentors)
    {
        if(chosen.size() == students.size())
        {
            int cnt = 0;
            for(int i = 0; i < students.size(); i++)
            {
                for(int j = 0; j < students[i].size(); j++)
                {
                    if(students[chosen[i]][j] == mentors[i][j])cnt++;
                }
            }
            ans = max(ans, cnt);
        } else 
        {
            for(int i = 0; i < students.size(); i++)
            {
                if(!isChosen[i])
                {
                    chosen.push_back(i);
                    isChosen[i] = true;
                    find(chosen, isChosen, students, mentors);
                    chosen.pop_back();
                    isChosen[i] = false;
                }
            }
        }
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        vector<int> chosen;
        vector<bool> isChosen(8, false);
        find(chosen, isChosen, students, mentors);
        return ans;
    }
};