class Solution {
public:
    bool check(int idx, vector<vector<int>> &pre, vector<bool> &inChecking, vector<bool> &isDone)
    {
        if(inChecking[idx])
        {
            if(!isDone[idx]) return false;
            return true;
        }

        inChecking[idx] = true;
        bool isPossible = true;
        for(int i = 0; i < pre[idx].size(); i++)
        {
            isPossible &= check(pre[idx][i], pre, inChecking, isDone);
        }
        isDone[idx] = true;
        return isPossible;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> pre(numCourses);
        vector<bool> inChecking(numCourses, false);
        vector<bool> isDone(numCourses, false);

        for(const auto& ho:prerequisites)
        {
            int a = ho[0], b = ho[1];
            pre[b].push_back(a);
        }

        bool ans = true;
        for(int i = 0; i < numCourses; i++)
        {
            if(!isDone[i])
            {
                ans &= check(i, pre, inChecking, isDone);
            }
        }

        return ans;
    }
};