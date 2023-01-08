class Solution:
    def gcd(self, a, b):
        if(b > a):
            return self.gcd(b, a)
        elif(b == 0):
            return a
        return self.gcd(b, a % b)

    def maxPoints(self, points: List[List[int]]) -> int:
        slope = {}
        for i in range(len(points)):
            x1, y1 = points[i]
            for j in range(i + 1, len(points)):
                x2, y2 = points[j]
                new_slope = None
                if(x1 - x2 == 0):
                    new_slope = (100000, x1, 0)
                elif(y1 - y2 == 0):
                    new_slope = (y1, 100000, 0)
                else:
                    dy = y1 - y2
                    dx = x1 - x2
                    GCD = self.gcd(abs(dy), abs(dx))
                    negative = True if dy * dx < 0 else False
                    dy = abs(dy) // GCD
                    dx = abs(dx) // GCD
                    if(negative):
                        dy = -dy
                    c = x1 * dy - y1 * dx
                    new_slope = (dy, dx, c)
                if(new_slope not in slope):
                    slope[new_slope] = 1
                else:
                    slope[new_slope] += 1
        ans = 0
        if(slope):
            ans = max(slope.values()) * 2
        return int(ans ** 0.5) + 1