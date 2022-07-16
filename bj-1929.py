def is_prime(n):
    for i in range(2, int(n ** 0.5) + 1):
        if(n % i == 0):return False
    return n != 1 and True
lis = input().split()
m, n = int(lis[0]), int(lis[1])
for i in range(m, n + 1):
    if(is_prime(i)):
        print(i)