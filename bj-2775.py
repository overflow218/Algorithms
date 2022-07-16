t = int(input())
for h in range(t):
    k = int(input())
    n = int(input())
    lis = [i for i in range(n + 1)]
    for i in range(k):
        lis = [(sum(lis[: j + 1]))for j in range(n + 1)]
    print(lis[n])