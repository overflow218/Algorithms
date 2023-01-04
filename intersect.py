from collections import Counter

class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        ans = []
        counter1 = Counter(nums1)
        counter2 = Counter(nums2)
        for n in counter1:
            cnt = min(counter1[n], counter2[n])
            for _ in range(cnt):
                ans.append(n)
        return ans