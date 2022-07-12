from collections import Counter
ans = Counter(input().upper()).most_common()
print(ans[0][0] if len(ans) == 1 or ans[0][1] > ans[1][1] else "?")