class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        consecutive = nums[0]
        cnt, ans = 0, 0
        lis = []
        for i in nums:
            if(i == consecutive):
                cnt += 1
            else:
                lis.append(cnt if consecutive == 1 else -cnt)
                cnt = 1
                consecutive = i
        lis.append(cnt if consecutive == 1 else -cnt)
        
        if(len(lis) == 1):
            return 1 if lis[0] < 0 else lis[0]
        for i in range(len(lis)):
            if(lis[i] > 0):
                ans = max(ans, lis[i] + 1)
            else:
                if(lis[i] == -1):
                    left = 0 if i == 0 else lis[i - 1]
                    right = 0 if i == len(lis) - 1 else lis[i + 1]
                    ans = max(ans, left + right + 1)
        return ans
            