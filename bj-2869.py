lis = list(map(int, input().split()))
a, b, v = lis[0], lis[1], lis[2]
print(1 + (v - b - 1) // (a - b))