/*
O(log(m + n))에 해결해야한다고 함. 
그러려면 이분탐색 느낌으로다가 해결해야할것 같음. 
일단 양쪽 배열 최솟값중 최솟값, 최댓값중, 최댓값을 찾은다음에 이걸 기준으로 이분탐색해야겠음
그래서 저거보다 작은것들이 몇개 있는지를 측정하는 방식으로 
k번째 수를 찾아가는 느낌으로 하면 되지 않을까? 
즉,m + n 이 짝수일때는 중간값 찾으려면 수를 2개 찾아야하니까 
주어진 두 배열에서 k번째 k + 1번째를 이분탐색으로 효율적으로 찾는 방법을 만들면 이 문제를 해결할 수 있을것 같음. 
*/
#include <algorithm>
class Solution {
public:
    int cnt = 0;

    // nums에 target보다 작은게 몇개 있는지 반환함
    int getCount(int target, vector<int>& nums)
    {
        if(target < nums[0]) return 0;
        if(target >= nums.back()) return nums.size();
        int idx = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        return nums[idx] == target ? idx + 1 : idx;
    }

    int find(int s, int e, int k, vector<int>& nums1, vector<int>& nums2)
    {
        while(s <= e)
        {
            
            int mid = (s + e) / 2;
            int cnt1 = getCount(mid, nums1);
            int cnt2 = getCount(mid, nums2);
            int cnt = cnt1 + cnt2;
            if(s == e)
            {
                if(cnt < k) return mid + 1;
                return mid;
            }
            if(cnt < k)
            {
                s = mid + 1;
            }
            if(cnt > k)
            {
                e = mid - 1;
                if(mid == min(nums1[0], nums2[0])) return mid;
            }
            if(cnt == k)
            {
                if(cnt1 == 0) return nums2[cnt2 - 1];
                if(cnt2 == 0) return nums1[cnt1 - 1];
                return max(nums1[cnt1 - 1], nums2[cnt2 - 1]);
            }
        }
        return 0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        int k = total / 2;
        if(nums1.size() == 0)
        {
            if(total % 2 == 0) return (nums2[k - 1] + nums2[k]) / 2.0;
            return nums2[k];
        }
        if(nums2.size() == 0)
        {
            if(total % 2 == 0) return (nums1[k - 1] + nums1[k]) / 2.0;
            return nums1[k];
        }
        int small = min(nums1[0], nums2[0]);
        int big = max(nums1.back(), nums2.back());
        if(total % 2 == 0) return (find(small, big, k, nums1, nums2) + find(small, big, k + 1, nums1, nums2)) / 2.0;
        return find(small, big, k + 1, nums1, nums2);
    }
};