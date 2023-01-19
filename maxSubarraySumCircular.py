from collections import deque
class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        ans = -300000
        tmp_sum = -300000
        pSum, pMax = 0, -300000
        front = []
        back = []
        for num in nums:
            if(tmp_sum > 0):
                tmp_sum += num
            else:
                tmp_sum = num
            pSum += num
            pMax = max(pMax, pSum)
            front.append(pMax)
            ans = max(ans, tmp_sum)

        pSum, pMax = 0, -300000
        for num in nums[::-1]:
            pSum += num
            pMax = max(pMax, pSum)
            back.append(pMax)
        
        for i in range(len(nums) - 1):
            ans = max(ans, front[i] + back[len(nums) - 2 - i])

        return ans
            