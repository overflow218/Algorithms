class Solution:
    def isValid(self, s: str) -> bool:
        left = {'(': 0, '[': 1, '{': 2}
        right = {')': 0, ']': 1, '}': 2}
        stack = []
        
        for c in s:
            if(c in left):
                stack.append(left[c])
            else:
                if(not stack or stack[-1] != right[c]):
                    return False
                stack.pop()
        return True if not stack else False
                
        