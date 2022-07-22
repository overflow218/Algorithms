import math
def count(x):
    cnt = 0
    while(x > 0 and x % 10 == 0):
        cnt += 1
        x = x // 10 
    return cnt
n = int(input())
print(count(math.factorial(n)))

n = int(input())
cnt2, cnt5 = 0, 0
for i in range(2, n + 1):
    while(i % 2 == 0):
        cnt2 += 1
        i = i // 2
    while(i % 5 == 0):
        cnt5 += 1
        i = i // 5
print(min(cnt2, cnt5))