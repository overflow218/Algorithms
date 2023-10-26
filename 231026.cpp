/*
leetcode 849번
*/
using namespace std;
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int> vec;
        for(int i = 0; i < seats.size(); i++)
        {
            if(seats[i] == 1) vec.push_back(i);
        }

        int ans = 0;
        if(seats[0] == 0) ans = vec[0];
        if(seats.back() == 0) ans = max(ans, (int)seats.size() - 1 - (int)vec.back());
        for(int i = 1; i < vec.size(); i++)
        {
            ans = max(ans, (vec[i] - vec[i - 1]) / 2);
        }
        return ans;
    }
};
