n = int(input())
for i in range(n):
    check = input()
    cnt = 0
    for c in check:
        if(c == '('):
            cnt += 1
        else:
            cnt -= 1
            if(cnt < 0): 
                break
    ans = "YES" if cnt == 0 else "NO"
    print(ans)