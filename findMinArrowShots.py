class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort()
        points.append([2 ** 31, -2 ** 31])
        start, end = points[0][0], points[0][1]
        cnt = 0
        for point in points[1:]:
            pStart, pEnd = point
            if(end < pStart):
                cnt += 1
                start, end = pStart, pEnd
            else:
                start = max(start, pStart)
                end = min(end, pEnd)
        return cnt