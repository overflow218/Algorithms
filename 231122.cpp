/*
leetcode 1424번
그냥 단순히 탐색하면 시간초과뜨네?
대각선에 있는것들은 x + y 가 같다는거 이용해서 정렬해주면 될듯
*/

#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> ans;

    bool static cmp(pair<int, int> a, pair<int, int> b){
        int aSum = a.first + a.second;
        int bSum = b.first + b.second;
        if(aSum != bSum) return aSum < bSum;
        return a.first > b.first;
    }
    
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<pair<int, int>> vec;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < nums[i].size(); j++)
            {
                vec.push_back(make_pair(i, j));
            }
        }
        sort(vec.begin(), vec.end(), cmp);
        for(auto &it: vec)
        {
            ans.push_back(nums[it.first][it.second]);
        }
        return ans;
    }
};
