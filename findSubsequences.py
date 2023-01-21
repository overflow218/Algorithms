class Solution:
    check = []
    number = []
    tmp = []
    def find(self, idx):
        if(idx == len(self.number)):
            return
        self.tmp.append(self.number[idx])
        if(len(self.tmp) >= 2 and self.tmp not in self.check):
            self.check.append(self.tmp[::])
        for i in range(idx + 1, len(self.number)):
            if(self.tmp[-1] <= self.number[i]):
                self.find(i)
        self.tmp.pop()

        
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        self.number = nums
        self.check = []
        for i in range(len(nums)):
            self.find(i)

        return self.check