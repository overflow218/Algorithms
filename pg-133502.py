def check(stack): # 1 2 3 1
    if(len(stack) >= 4 and stack[-1] == 1 and stack[-4] == 1 and stack[-3] == 2 and stack[-2] == 3): return True
    return False

def solution(ingredient):
    answer = 0
    stack = []
    for idx, value in enumerate(ingredient):
        stack.append(value)
        if(check(stack)):
            for i in range(4):
                stack.pop()
            answer = answer + 1
    return answer