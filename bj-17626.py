n = int(input())
lis = [0] * (n + 1)
for i in range(1, n + 1):
    limit = int(i ** 0.5)
    ans = 987654321
    for j in range(1, limit + 1):
        ans = min(ans, lis[i - j * j] + 1)
    lis[i] = ans
print(lis[n])