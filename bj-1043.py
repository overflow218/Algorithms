import sys

a = list(map(int, sys.stdin.readline().split()))
n, m = a[0], a[1]

a = list(map(int, sys.stdin.readline().split()))
oracle = set(a[1:])

party = []
for i in range(m):
    a = list(map(int, sys.stdin.readline().split()))
    party.append(a[1:])
    oracle = oracle | set(a[1:]) if len(oracle & set(a[1:])) > 0 else oracle

while(True):
    realOracle = oracle
    for i in oracle:
        for p in party:
            if i in p:
                realOracle = realOracle | set(p)
    if(realOracle == oracle): break
    oracle = realOracle

cnt = 0
for p in party:
    if(len(set(p) & oracle) == 0):
        cnt += 1
print(cnt)