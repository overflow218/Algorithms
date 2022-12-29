import heapq
class MinStack:

    def __init__(self):
        self.stack = []
        self.minimum = 2 ** 31 - 1
        self.check = {}


    def push(self, val: int) -> None:
        self.stack.append(val)
        self.check[(len(self.stack), val)] = self.minimum
        self.minimum = min(self.minimum, val)

    def pop(self) -> None:
        idx, val = len(self.stack), self.stack.pop()
        self.minimum = self.check[(idx, val)]
        
    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.minimum

        
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()