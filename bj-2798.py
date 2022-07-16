lis = input().split()
n, m = int(lis[0]), int(lis[1])
cart = list(map(int, input().split()))
ans = 0
for i in range(n):
    for j in range(i + 1, n):
        for k in range(j + 1, n):
            ans = max(ans, cart[i] + cart[j] + cart[k]) if cart[i] + cart[j] + cart[k] <= m else ans
print(ans)