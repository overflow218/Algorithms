def fun():
    n = int(input())
    ans = -1
    for i in range(n // 5, -1, -1):
        for j in range(n // 3 + 1):
            if(5 * i + 3 * j == n):
                print(i + j)
                return
    print(-1)
fun()