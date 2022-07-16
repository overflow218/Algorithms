t = int(input())
for i in range(t):
    lis = list(map(int, input().split()))
    print(f"{lis[2] % lis[0] if lis[2] % lis[0] else lis[0]}{str((lis[2] + lis[0] - 1) // lis[0]).zfill(2)}")