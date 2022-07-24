import sys
n = int(sys.stdin.readline())
m = int(sys.stdin.readline())
s = sys.stdin.readline().strip()
s = s.replace('II', 'I I')
s = s.replace('OO', 'O O')
s = s.replace('IIO', 'I IO')
s = s.replace('OOI', 'OO I')
s = s.split()
s = [(len(i) - 1) // 2 for i in s]
ans = sum([i - n + 1 for i in s if i >= n])
print(ans)