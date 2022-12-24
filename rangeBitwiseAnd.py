class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        if(left == right):
            return left
        parsedLeft = []
        parsedRight = []
        while(left):
            parsedLeft.append(left % 2)
            left //= 2
        while(right):
            parsedRight.append(right % 2)
            right //= 2
        if(len(parsedLeft) != len(parsedRight)):
            return 0
        ho = [0] * len(parsedLeft)
        for i in range(len(parsedLeft)):
            if(parsedLeft[-1 -i] == parsedRight[-1 -i]):
                ho[i] = parsedLeft[-1 -i]
            else:
                break
        return sum([0 if ho[i] == 0 else 1 << (len(ho) - 1 -i) for i in range(len(ho))])
            
        