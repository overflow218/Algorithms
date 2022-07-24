n = int(input())
lis = list(map(int, input().split()))
ans = sum([ value * (n - idx) for idx, value in enumerate(sorted(lis))])
print(ans)