class Solution:
    def findBlackPixel(self, picture: List[List[str]], target: int) -> int:
        # candidate = list(filter(lambda x: x.count('B') == target, picture))
        picture.sort()
        valid_row = [row.count('B') == target for row in picture]
        ans = 0
        for col in range(len(picture[0])):
            tmp = []
            isPossible = True
            for row in range(len(picture)):
                if(picture[row][col] == 'B'):
                    if(not valid_row[row]):
                        isPossible = False
                        break
                    tmp.append(row)
            if(isPossible and len(tmp) == target and picture[tmp[0]] == picture[tmp[-1]]):
                ans += target
        return ans