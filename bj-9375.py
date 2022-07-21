import sys
t = int(sys.stdin.readline())
for k in range(t):
    n = int(sys.stdin.readline())
    dic = {}
    for i in range(n):
        input = sys.stdin.readline().split()
        if(input[1] in dic):
            dic[input[1]] += 1
        else:
            dic[input[1]] = 1
    ans = 1
    for i in dic:
        ans *= dic[i] + 1
    print(ans - 1)