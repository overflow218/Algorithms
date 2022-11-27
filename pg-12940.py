def gcd(a, b):
    if(b > a): return gcd(b, a)
    return a if b == 0 else gcd(b, a % b)
def solution(n, m):
    return [gcd(n, m), n // gcd(n, m) * m]