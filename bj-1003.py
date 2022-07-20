import sys
t = int(sys.stdin.readline())
lis = [int(sys.stdin.readline()) for i in range(t)]
fibo = [[1, 0], [0, 1]]
for i in range(39):
    fibo.append(([fibo[-1][0] + fibo[-2][0], fibo[-1][1] + fibo[-2][1]]))
for i in lis:
    print(fibo[i][0], fibo[i][1])