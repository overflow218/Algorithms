s = [i for i in input()]
for i in range(26):
    try:
        print(s.index(chr(ord('a') + i)), end = " ")
    except:
        print(-1, end = " ")