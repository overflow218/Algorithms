class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        dic = {}
        for i, v in enumerate(numbers):
            comp = target - v
            if(comp in dic): 
                return [dic[comp], i + 1]
            dic[v] = i + 1
        