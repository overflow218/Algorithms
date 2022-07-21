def count(n):
    cnt = 0
    while(n > 0 and n % 10 == 0):
        cnt += 1
        n = n // 10 
    return cnt
n = int(input())
last, cnt = 1, 0 if n > 0 else 1
for i in range(1, n + 1):
    last = last * i
    c = count(last)
    cnt = cnt + c
    x = str(last)[:-c]
    last = int(str(last)[:-c][0]) if c > 0 else last % 10
print(cnt)