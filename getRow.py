class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        prev = [1]
        cur = [1]
        idx = 1
        while(idx <= rowIndex):
            for i in range(idx):
                cur[i] = 1 if i == 0 else prev[i] + prev[i - 1]
            cur.append(1)
            prev = cur[:]
            idx += 1
        return cur
        