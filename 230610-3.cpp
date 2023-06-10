class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = n - 1;
        while(s <= e)
        {
            int mid = (s + e) / 2;
            if((mid == 0 || nums[mid - 1] < nums[mid]) && (mid == n -1 || nums[mid] > nums[mid + 1])) return mid;
            if(mid > 0 && nums[mid - 1] > nums[mid]) e = mid - 1;
            else if(mid < n - 1 && nums[mid + 1] > nums[mid]) s = mid + 1;
        }
        return -1;   
    }
};