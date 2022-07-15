import functools
n = int(input())
lis = []
for i in range(n):
    lis.append(input())
lis = sorted(list(set(lis)), key = functools.cmp_to_key(lambda x, y : len(x) - len(y) if len(x) != len(y) else -1 if x < y else 1))
for i in lis:
    print(i)