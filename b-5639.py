import sys
from bisect import bisect_right
lines = sys.stdin.readlines()
tree = [int(n) for n in lines]

def find(s, e):
    if(s >= e):
        if(s == e):
            print(tree[s])
        return
    idx = bisect_right(tree, tree[s])
    find(s + 1, idx - 1)
    find(idx, e)
    print(tree[s])

print(tree)
find(0, len(tree) - 1)