n = int(input())
lis = [3 * i * (i + 1) + 1 for i in range(100000)]
for i in range(len(lis)):
    if(n <= lis[i]):
        print(i + 1)
        break