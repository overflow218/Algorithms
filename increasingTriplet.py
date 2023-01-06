class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        candidate = []
        for num in nums:
            if(not candidate or candidate[-1] < num):
                candidate.append(num)
            if(len(candidate) == 3):
                return True
            for i in range(len(candidate)):
                if(num == candidate[i]):
                    break
                elif(num < candidate[i]):
                    candidate[i] = num
                    break
        return False