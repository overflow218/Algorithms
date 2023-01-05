class Solution:
    def findLonelyPixel(self, picture: List[List[str]]) -> int:
        ans = 0
        row, col = len(picture), len(picture[0])
        for c in range(col):
            check = []
            for r in range(row):
                if(picture[r][c] == 'B'):
                    check.append(r)
            if(len(check) == 1):
                ans += 1 if picture[check[0]].count('B') == 1 else 0
        return ans

