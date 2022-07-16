lis = list(map(int, input().split()))
while(lis != [0, 0, 0]):
    lis.sort()
    ans = "right" if lis[2] ** 2 == lis[0] ** 2 + lis[1] ** 2 else "wrong"
    print(ans)
    lis = list(map(int, input().split()))