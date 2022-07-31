import sys
t = int(sys.stdin.readline())
for h in range(t):
    n = int(sys.stdin.readline())
    sticker = [list(map(int, sys.stdin.readline().split())) for i in range(2)]
    if(n > 1):
        sticker[0][1] = sticker[1][0] + sticker[0][1]
        sticker[1][1] = sticker[0][0] + sticker[1][1]
    for i in range(2, n):
        sticker[0][i] = sticker[1][i - 1] + sticker[0][i] if sticker[1][i - 1] > max(sticker[0][i - 2], sticker[1][i - 2]) else max(sticker[0][i - 2], sticker[1][i - 2]) + sticker[0][i]
        sticker[1][i] = sticker[0][i - 1] + sticker[1][i] if sticker[0][i - 1] > max(sticker[0][i - 2], sticker[1][i - 2]) else max(sticker[0][i - 2], sticker[1][i - 2]) + sticker[1][i]
    print(max(sticker[0][n - 1], sticker[1][n - 1]))