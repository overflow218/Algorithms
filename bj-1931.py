import sys
import functools
n = int(input())
meeting = []
for i in range(n):
    meeting.append(list(map(int, sys.stdin.readline().split())))
meeting = sorted(meeting, key = functools.cmp_to_key(lambda x, y : x[1] - y[1] if x[1] != y[1] else x[0] - y[0]))
cnt, prev = 0, 0
for i in meeting:
    if(i[0] >= prev):
        prev = i[1]
        cnt += 1
print(cnt)