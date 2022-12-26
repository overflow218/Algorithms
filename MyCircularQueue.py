class MyCircularQueue:

    def __init__(self, k: int):
        self.q = [0 for i in range(k)]
        self.head = 0
        self.tail = 0
        self.k = k
        self.size = 0
        
    def enQueue(self, value: int) -> bool:
        if(not self.isFull()):
            self.q[self.tail] = value
            self.tail = (self.tail + 1) % self.k
            self.size += 1
            return True
        return False
        
    def deQueue(self) -> bool:
        if(not self.isEmpty()):
            self.head = (self.head + 1) % self.k
            self.size -= 1
            return True
        return False
        
    def Front(self) -> int:
        if(self.isEmpty()):
            return -1
        return self.q[self.head]
        
    def Rear(self) -> int:
        if(self.isEmpty()):
            return -1
        return self.q[(self.tail + self.k - 1) % self.k]
        
    def isEmpty(self) -> bool:
        return self.head == self.tail and self.size == 0
        
    def isFull(self) -> bool:
        return self.head == self.tail and self.size > 0
        


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()