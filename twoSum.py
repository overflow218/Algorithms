class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dic = {}
        for idx, value in enumerate(nums):
            if(value in dic):
                dic[value].append(idx)
            else:
                dic[value] = [idx]

        for idx, value in enumerate(nums):
            if(target - value in dic):
                if(value != target - value):
                    return [idx, dic[target-value][0]]
                else:
                    if(len(dic[value]) > 1):
                        return dic[value]
        return []