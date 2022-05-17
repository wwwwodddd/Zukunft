class MyQueue:

    def __init__(self):
        self.a = []
        self.b = []

    def push(self, x: int) -> None:
        self.b.append(x)

    def pop(self) -> int:
        if len(self.a) == 0:
            while len(self.b):
                self.a.append(self.b.pop())
        return self.a.pop()

    def peek(self) -> int:
        if len(self.a) == 0:
            while len(self.b):
                self.a.append(self.b.pop())
        return self.a[-1]

    def empty(self) -> bool:
        return len(self.a) == 0 and len(self.b) == 0
        


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()