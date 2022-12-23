class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        idx = -1
        candidate = []
        for i, v in enumerate(nums):
            if(len(candidate) < 2):
                candidate.append(v)
                if(len(candidate) == 1):
                    idx= i
            if(candidate[-1] < v):
                candidate[-1] = v
            if(len(candidate) == 2 and candidate[0] < candidate[1]):
                idx = i
                candidate[0], candidate[1] = candidate[1], candidate[0]
            
        return idx if (len(candidate) == 1 or candidate[0] >= 2 * candidate[1]) else -1
                    
        