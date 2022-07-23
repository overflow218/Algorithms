n = int(input())
ans = [0, 0, 1]
for i in range(3, n + 1):
    tmp = [ans[i - 1] + 1]
    if(i % 3 == 0):
        tmp.append(ans[i // 3] + 1)
    if(i % 2 == 0):
        tmp.append(ans[i // 2] + 1)
    ans.append(min(tmp))
print(ans[n])