cnt = 0
lis = list(map(int, input().split()))
N, r, c = lis[0], lis[1], lis[2]
lis = [[0] * (2 ** N) for i in range(2 ** N)]
def go(x, y, n):
    global cnt
    if(n == 1):
        lis[x][y] = cnt
        lis[x][y + 1] = cnt + 1
        lis[x + 1][y] = cnt + 2
        lis[x + 1][y + 1] = cnt + 3
        cnt += 4
    else:
        go(x, y, n - 1)
        go(x, y + 2 ** (n - 1), n - 1)
        go(x + 2 ** (n - 1), y, n - 1)
        go(x + 2 ** (n - 1), y + 2 ** (n - 1), n - 1)
go(0, 0, N)
print(lis[r][c])