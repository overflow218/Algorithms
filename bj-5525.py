import sys
n = int(sys.stdin.readline())
m = int(sys.stdin.readline())
s = sys.stdin.readline().strip()
prev = 'O' if s[0] == 'I' else 'I'
lis = []
cnt = 0
for i in s:
    if(i == prev):
        lis.append(cnt - 1)
        cnt = 1 if i == 'I' else 0
    else:
        prev = i 
        if(i == 'I'): cnt += 1
lis.append(cnt - 1)
print(sum([i - n + 1 for i in lis if i >= n]))