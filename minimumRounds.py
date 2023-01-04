'''
개수가 3으로 나눠 떨어지거나 mod3 == 0 
3으로 나눴을때 2가 나와야함 mod3 == 2 
왜냐면 최소횟수를 구해야하기 때문에 3을 최대한 많이 사용하는게 좋음. 
7은 2 2 3 으로도 되넹..
'''
from collections import Counter
class Solution:

    def find(self, v: int) -> int:
        if(v % 3 == 0):
            return v // 3
        elif(v % 3 == 2):
            return (v // 3) + 1
        else:
            if(v >= 4):
                return 2 + self.find(v - 4)
            return -1

    def minimumRounds(self, tasks: List[int]) -> int:
        count = Counter(tasks)
        print(count)
        ans = 0
        for v in count.values():
            cnt = self.find(v)
            if(cnt == -1):
                return -1
            ans += cnt
        return ans