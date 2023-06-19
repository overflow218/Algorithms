#include <algorithm>
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int s = 0, e = m - 1, idx = 0;
        while(s <= e)
        {
            int mid = (s + e) / 2;
            if(matrix[mid][0] == target) return true;
            if(matrix[mid][0] < target)
            {
                s = mid + 1;
                idx = mid;
            }
            if(matrix[mid][0] > target) e = mid - 1;
        }
        int r = lower_bound(matrix[idx].begin(), matrix[idx].end(), target) - matrix[idx].begin();
        if(r == n || matrix[idx][r] != target) return false;
        return true;
    }
};