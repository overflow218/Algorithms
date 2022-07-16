from math import factorial
lis = list(map(int, input().split()))
print(factorial(lis[0]) // factorial(lis[1]) // factorial(lis[0] - lis[1]))