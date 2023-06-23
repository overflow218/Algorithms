class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx1 = 0, idx2 = 0;
        vector<int> vec(nums1.begin(), nums1.end());
        while(idx1 + idx2 < m + n)
        {
            if(idx1 == m || (idx2 < n && vec[idx1] > nums2[idx2]))
            {
                nums1[idx1 + idx2] = nums2[idx2];
                idx2++;
                continue;
            }
            if(idx2 == n || (idx1 < m && vec[idx1] <= nums2[idx2]))
            {
                nums1[idx1 + idx2] = vec[idx1];
                idx1++;
            }
        }
    }
};