import bisect
class Solution:
    def maximumTastiness(self, price: List[int], k: int) -> int:
        price.sort()
        start, end = 0, price[-1]
        ans = 0
        while(start <= end):
            mid = (start + end) // 2
            idx = 0
            isOkay = True
            for _ in range(k- 1):
                idx = bisect.bisect_left(price, price[idx] + mid)
                if(idx == len(price)):
                    end = mid - 1
                    isOkay = False
                    break
            if(isOkay):
                ans = max(ans, mid)
                start = mid + 1
        return ans
            
            
        