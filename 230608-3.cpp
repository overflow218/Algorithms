class Solution {
public:
    vector<long long> cache = vector<long long>(100000, -1);
    long long find(int idx, vector<vector<int>>& questions)
    {
        if(idx >= questions.size()) return 0;
        long long &ret = cache[idx];
        if(ret != -1) return ret;
        return ret = max(find(idx + 1, questions), (long long) questions[idx][0] + find(idx + questions[idx][1] + 1, questions));
    }
    long long mostPoints(vector<vector<int>>& questions) {
        return find(0, questions);
    }
};