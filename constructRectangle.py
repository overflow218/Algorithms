class Solution:
    def constructRectangle(self, area: int) -> List[int]:
        diff = area
        ans = None
        for i in range(1, int(area ** 0.5) + 1):
            if(area % i == 0):
                a, b = i, area // i
                if(abs(a - b) < diff):
                    ans = (max(a, b), min(a, b))
        return ans