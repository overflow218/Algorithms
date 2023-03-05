class Solution:
    def isValid(self, s: str) -> bool:
        openBracket = "([{"
        closeBracket = ")]}"
        opposite = { ')' : '(', ']' : '[', '}' : '{'}

        stack = []
        for c in s:
            if c in openBracket:
                stack.append(c)
            else:
                if(len(stack) == 0 or stack[-1] != opposite[c]):
                    return False
                stack.pop()
        return True if len(stack) == 0 else False
                