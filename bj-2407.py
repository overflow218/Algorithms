lis = list(map(int, input().split()))
n, m = lis[0], lis[1]
arr = [[0] * 101 for i in range(101)]
arr[2][0] = 1
arr[2][1] = 2
arr[2][2] = 1

for i in range(3, n + 1):
    for j in range(i + 1):
        arr[i][j] = 1 if j == 0 or j == i else arr[i - 1][j] + arr[i - 1][j - 1]

print(arr[n][m])