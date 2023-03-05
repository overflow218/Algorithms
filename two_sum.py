class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        check = { num: [] for num in nums}
        for i in range(len(nums)):
            check[nums[i]].append(i)
        for num in nums:
            tmp = target - num
            if(tmp in check):
                if(num == tmp and len(check[num]) > 1): 
                    return check[num]
                if(num != tmp):
                    return [check[num][0], check[tmp][0]]
