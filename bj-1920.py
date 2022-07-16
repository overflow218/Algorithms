n = int(input())
lis = input().split()
dic = {}
for i in lis:
    dic[i] = 1
m = input()
check = input().split()
for i in check:
    print(dic.get(i, 0))
