from collections import Counter
a = int(input())
b = int(input())
c = int(input())
x = Counter(str(a * b * c))
for i in range(10):
    print(x[str(i)])