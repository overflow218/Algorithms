ans, idx = 0, 1
for i in range(9):
    tmp = int(input())
    if(tmp > ans):
        ans, idx = tmp, i + 1
print(ans)
print(idx)