def is_prime(n):
    for i in range(2, int(n ** 0.5) + 1):
        if(n % i == 0): return False
    return n != 1 and True
import sys
n = int(input())
lis = list(map(int, input().split()))
print(len([i for i in lis if is_prime(i)]))