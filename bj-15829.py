def hash(n):
    ans = 1
    for i in range(n):
        ans *= 31
        ans %= 1234567891
    return ans

r , m = 31, 1234567891
n = int(input())
s = input()
dic = {}
for i in range(26):
    dic[chr(ord('a') + i)] = i + 1
print(sum([dic[s[i]] * hash(i) % m for i in range(n)]) % m)