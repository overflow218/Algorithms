from collections import deque
n = int(input())
candi = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
lis = []
for i in candi:
    for j in candi:
        for k in candi:
            for l in candi:
                lis.append(int(i + j + k + l + '666'))
                lis.append(int(i + j + k + '666' + l))
                lis.append(int(i + j + '666' + k + l))
                lis.append(int(i + '666' + j + k + l))
                lis.append(int('666' + i + j + k + l))
lis = sorted(list(set(lis)))
print(lis[n - 1])