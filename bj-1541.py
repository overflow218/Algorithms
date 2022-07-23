a = input()
parsing = a.split('-')
ans = [sum(list(map(int, (i.split('+'))))) for i in parsing]
print(ans[0] - sum(ans[1:]))