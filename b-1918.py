from collections import deque
check = input()
global idx
idx = 0
def find():
    global idx
    left = deque([])
    oper = deque([])
    while(idx < len(check)):
        if(check[idx] == ')'):
            idx += 1
            break
        elif(check[idx] in '+-*/'):
            oper.append(check[idx])
            idx += 1
        else:
            if(check[idx] == '('):
                idx += 1
                left.append(find())
            else:
                left.append(check[idx])
                idx += 1
            if(oper and oper[-1] in '*/'):
                b = left.pop()
                a = left.pop()
                op = oper.pop()
                left.append(a + b + op)

    limit = len(oper)
    for _ in range(limit):
        a = left.popleft()
        b = left.popleft()
        op = oper.popleft()
        left.appendleft(a + b + op)
    return left.pop()

print(find())