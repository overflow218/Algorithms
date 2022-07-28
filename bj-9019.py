import sys
from collections import deque

def D(n):
    return 2 * n if 2 * n < 10000 else (2 * n) % 10000
def S(n):
    return n - 1 if n > 0 else 9999
def R(n):
    return n // 10 + (n % 10) * 1000
def L(n):
    return n * 10 % 10000 + n // 1000

t = int(input())
for i in range(t):
    lis = sys.stdin.readline().split()
    a, b = int(lis[0]), int(lis[1])
    tmp = (a, '')
    dic = {}
    q = deque()
    q.append(tmp)
    while(len(q) > 0):
        current = q.popleft()
        if(current[0] in dic):
            continue
        if(current[0] == b):
            print(current[1])
            break
        else:
            dic[current[0]] = 0
            q.append((D(current[0]), current[1] + 'D'))
            q.append((S(current[0]), current[1] + 'S'))
            q.append((L(current[0]), current[1] + 'L'))
            q.append((R(current[0]), current[1] + 'R'))