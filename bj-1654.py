a = input().split()
k, n = int(a[0]), int(a[1])
lis = []
for i in range(k):
    lis.append(int(input()))
ans = max(lis)
start, end = 1, ans
while(start <= end):
    mid = (start + end) // 2
    cnt = sum([i // mid for i in lis])
    if(cnt >= n):
        start = mid + 1
        ans = mid
    else:
        end = mid - 1
print(ans)