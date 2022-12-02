import re

def fun(oper, num1, num2):
    if(oper == '*'):
        return num1 * num2
    if(oper == '+'):
        return num1 + num2
    return num1 - num2
def solution(expression):
    answer = 0
    number = list(map(int, re.findall('\d+',expression)))
    oper = list(filter(lambda x: x != '',re.split('\d+',expression)))
    priority = [['*', '+', '-'], ['*', '-', '+'], ['+', '-', '*'], ['+', '*', '-'], ['-', '+', '*'],['-', '*', '+']]
    for p in priority:
        tmp_number = number[:]
        tmp_oper = oper[:]
        for op in p:
            idx = 0
            while(idx < len(tmp_oper)):
                if(tmp_oper[idx] == op):
                    tmp_number[idx + 1] = fun(op, tmp_number[idx], tmp_number[idx + 1])
                    tmp_oper.pop(idx)
                    tmp_number.pop(idx)
                else:
                    idx += 1
        answer = max(answer, abs(tmp_number[0]))
    return answer