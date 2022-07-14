t = int(input())
for i in range(t):
    s = input()
    sum, cnt = 0, 0
    for j in s:
        if j == 'O':
            sum += cnt + 1
            cnt += 1
        else:
            cnt = 0
    print(sum)
