import sys
from collections import deque

def find(origin, bomb):
    if(bomb not in origin):
        return origin
    ret = ''
    splited = deque(origin.split(bomb))
    while(splited):
        a = splited.popleft()
        if(not splited):
            ret += a
            break
        b = splited.popleft()
        ret += find(a + b, bomb)
    return find(ret, bomb)

target = input()
bomb = input()

ans = find(target, bomb)
print(ans if ans else 'FRULA')
'''
aaaaaabbbbbb 이런거 어떻게 풀을래
'''