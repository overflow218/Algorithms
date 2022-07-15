size = input().split()
n, m = int(size[0]), int(size[1])
template = ['WBWBWBWB','BWBWBWBW','WBWBWBWB','BWBWBWBW','WBWBWBWB','BWBWBWBW','WBWBWBWB','BWBWBWBW']
board = []
for i in range(n):
    board.append(input())
ans = 64
for i in range(n - 8 + 1):
    for j in range(m - 8 + 1):
        tmp = sum([(sum([0 if c1 == c2 else 1 for c1, c2 in zip(board[i + idx][j : j + 8], template[idx % 2])])) for idx in range(8)])
        ans = min(ans, min(tmp, 64 - tmp))
print(ans)