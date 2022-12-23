class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        ans = [[1]]
        for i in range(2, numRows + 1):
            tmp_row = []
            for j in range(i):
                if(j == 0 or j == i - 1):
                    tmp_row.append(1)
                else:
                    tmp_row.append(ans[i - 2][j - 1] + ans[i - 2][j])
            ans.append(tmp_row)
        return ans
        