class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        spare = []
        idx1 = 0 
        idx2 = 0
        while(idx1 < m and idx2 < n):
            if(nums1[idx1] < nums2[idx2]):
                spare.append(nums1[idx1])
                idx1+=1
            else:
                spare.append(nums2[idx2])
                idx2+=1
        for i in range(idx1, m):
            spare.append(nums1[i])
        for i in range(idx2, n):
            spare.append(nums2[i])
        for i, v in enumerate(spare):
            nums1[i] = v