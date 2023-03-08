class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        oper = ["+", "-", "/", "*"]
        num = []

        for c in tokens:
            if(c in oper):
                b = num.pop()
                a = num.pop()
                x = 0
                # print(f"{a} {c} {b}")
                if(c == "+"):
                    x = a + b
                if(c == "-"):
                    x = a - b
                if(c == "*"):
                    x = a * b
                if(c == "/"):
                    x = abs(a) // abs(b)
                    check = 0
                    if(a < 0):
                        check += 1
                    if(b < 0):
                        check += 1
                    if(check == 1):
                        x = -x
                num.append(x)
            else:
                num.append(int(c))
        return num[0]