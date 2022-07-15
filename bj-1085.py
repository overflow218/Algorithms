lis = input().split()
x, y, w, h = int(lis[0]), int(lis[1]), int(lis[2]), int(lis[3])
print(min(min(x, w - x), min(y, h - y)))