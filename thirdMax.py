class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        lis = []
        for num in nums:
            if(len(lis) < 3 and num not in lis):
                lis.append(num)
            elif(lis[-1] < num and num not in lis):
                lis[-1] = num
            for i in range(len(lis) -1, 0, -1):
                if(lis[i] > lis[i - 1]):
                    lis[i], lis[i - 1] = lis[i -1], lis[i]
        return lis[0] if len(lis) < 3 else lis[-1]