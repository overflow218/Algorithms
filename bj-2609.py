def gcd(a, b):
    return a if b == 0 else gcd(b, a % b) if a >= b else gcd(b, a)
lis = input().split()
a, b = int(lis[0]), int(lis[1])
print(gcd(a, b))
print(a * b // gcd(a, b))