from collections import deque
s = input()
while(s != "."):
    s = s.strip()
    deq = deque()
    okay = True
    for c in s:
        if(c == '('): 
            deq.append(')')
        elif(c == ')'):
            if(len(deq) == 0 or deq[-1] != c):
                okay = False
                break
            deq.pop()
        elif(c == '['):
            deq.append(']')
        elif(c == ']'):
            if(len(deq) == 0 or deq[-1] != c):
                okay = False
                break
            deq.pop()
    ans = "yes" if len(deq) == 0 and okay else "no"
    print(ans)
    s = input()