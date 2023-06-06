class Solution:
    def reverse(self, x: int) -> int:
        isNegative = x < 0
        if(isNegative):
            x = -x
        ans = int(str(x)[::-1])
        # 범위 벗어나는 경우를 컷해줘야함.
        if(not isNegative and ans > int(2 ** 31 - 1)): return 0
        if(isNegative and ans > int(2 ** 31)): return 0
        return -ans if isNegative else ans