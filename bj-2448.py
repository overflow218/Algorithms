def fun(n):
    if(n == 3):
        return ["  *  ", " * * ", "*****"]
    prev = fun(n // 2)
    space = len(prev[0]) // 2 + 1
    ans = []
    for i in prev:
        ans.append(" " * space + i + " " * space)
    for i in prev:
        ans.append(i + " " + i)
    return ans

for i in fun(int(input())):
    print(i)