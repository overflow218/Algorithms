class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        oper = ['+', '-', '*', '/']
        stack = []
        for token in tokens:
            if (token == '+'):
                a, b = stack.pop(), stack.pop()
                stack.append(b + a)
            elif (token == '-'):
                a, b = stack.pop(), stack.pop()
                stack.append(b - a)
            elif (token == '*'):
                a, b = stack.pop(), stack.pop()
                stack.append(a * b)
            elif (token == '/'):
                a, b = stack.pop(), stack.pop()
                if(a * b < 0):
                    stack.append(- (abs(b) // abs(a)))
                else:
                    stack.append(b // a)
            else:
                stack.append(int(token))
        return stack[0]
        