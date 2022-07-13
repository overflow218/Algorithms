t = int(input())
for i in range(t):
    x = input().split()
    print("".join([i * int(x[0]) for i in x[1]]))