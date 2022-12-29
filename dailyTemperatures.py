class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stack = []
        ans = [0 for _ in range(len(temperatures))]
        for idx, val in enumerate(temperatures):
            if(stack):
                while(stack and stack[-1][1] < val):
                    pIdx, pVal = stack.pop()
                    ans[pIdx] = idx - pIdx
            stack.append((idx, val))    
        return ans
        