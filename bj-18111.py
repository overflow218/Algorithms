import sys
cons = input().split()
n, b = int(cons[0]), int(cons[2])
lis = []
for i in range(n):
    lis.append(list(map(int, sys.stdin.readline().split())))
lis = [y for x in lis for y in x]
low, high, time, height = min(lis), max(lis), 987654321, 0
while(low <= high):
    plus, minus = 0, 0
    for i in lis:
        if(i > low): plus += i - low
        if(i < low): minus += low - i
    if(plus + b >= minus):
        tmp_time = 2 * plus + minus
        if(tmp_time <= time):
            time = tmp_time
            height = low
    low += 1
print(time, height)