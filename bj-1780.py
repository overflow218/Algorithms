import sys
n = int(input())
paper = [list(map(int, sys.stdin.readline().split())) for i in range(n)]
ans = [0, 0, 0]
def check(x, y, size):
    global ans
    if(size == 1):
        ans[paper[x][y] + 1] += 1
    else:
        tmp = paper[x][y]
        is_same = True
        for i in range(size):
            for j in range(size):
                if(tmp != paper[x + i][y + j]):
                    is_same = False
                    break
            if(is_same == False):
                break
        if(is_same):
            ans[tmp + 1] += 1
        else:
            jump = size // 3
            check(x, y, size // 3)
            check(x + jump, y, size // 3)
            check(x + 2 * jump, y, size // 3)
            check(x, y + jump, size // 3)
            check(x + jump, y + jump, size // 3)
            check(x + 2 * jump, y + jump, size // 3)
            check(x, y + 2 * jump, size // 3)
            check(x + jump, y + 2 * jump, size // 3)
            check(x + 2 * jump, y + 2 * jump, size // 3)
check(0, 0, n)
print(ans[0])
print(ans[1])
print(ans[2])