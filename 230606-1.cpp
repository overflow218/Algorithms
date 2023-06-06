#include <algorithm>
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        for(int i = 0; i < arr.size() - 1; i++)
        {
            if(arr[i] - arr[i + 1] != arr[0] - arr[1]) return false;
        }
        return true;
    }
};