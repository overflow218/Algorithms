t = int(input())
lis = [0, 1, 2, 4]
for i in range(4, 12):
    lis.append(lis[i - 1] + lis[i - 2] + lis[i - 3])
for i in range(t):
    print(lis[int(input())])