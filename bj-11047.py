import sys
lis = sys.stdin.readline().split()
n, k = int(lis[0]), int(lis[1])
coin = [int(sys.stdin.readline()) for i in range(n)]
ans = 0
for i in reversed(coin):
    ans += k // i
    k = k % i
print(ans)