from collections import deque

class MyStack:

    def __init__(self):
        self.q1 = deque()
        self.q2 = deque()

    def push(self, x: int) -> None:
        if(self.q1):
            self.q1.append(x)
        else:
            self.q2.append(x)

    def pop(self) -> int:
        if(self.q1):
            cnt = len(self.q1) - 1
            for _ in range(cnt):
                self.q2.append(self.q1.popleft())
            return self.q1.popleft()
        else:
            cnt = len(self.q2) - 1
            for _ in range(cnt):
                self.q1.append(self.q2.popleft())
            return self.q2.popleft()

    def top(self) -> int:
        ret = None
        if(self.q1):
            cnt = len(self.q1) - 1
            for _ in range(cnt):
                self.q2.append(self.q1.popleft())
            ret = self.q1.popleft()
            self.q2.append(ret)
        else:
            cnt = len(self.q2) - 1
            for _ in range(cnt):
                self.q1.append(self.q2.popleft())
            ret = self.q2.popleft()
            self.q1.append(ret)
        return ret
        

    def empty(self) -> bool:
        return not self.q1 and not self.q2
        


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()