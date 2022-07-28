import sys
t = int(sys.stdin.readline())
for h in range(t):
    cmd = sys.stdin.readline().strip()
    n = int(sys.stdin.readline())
    a = sys.stdin.readline().strip()[1:-1].split(',')
    lis = list(map(int, a)) if n > 0 else []
    reverse, front, end = 0, 0, 0
    for c in cmd:
        if(c == 'R'):
            reverse += 1
        else:
            if(reverse % 2 == 0): 
                front += 1
            else: 
                end += 1
    if(front + end > n):
        print("error")
    elif(front + end == n):
        print([])
    else:
        if(n == 0):
            print([])
        elif(reverse % 2 == 0):
            tmp = lis[front:n - end]
            ans = '['
            for i in tmp:
                ans += str(i) + ','
            ans = ans[:-1] + ']'
            print(ans)
        else:
            tmp = lis[front:n - end]
            ans = '['
            for i in tmp[::-1]:
                ans += str(i) + ','
            ans = ans[:-1] + ']'
            print(ans)