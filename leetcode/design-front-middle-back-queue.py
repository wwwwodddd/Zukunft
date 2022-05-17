class FrontMiddleBackQueue:

    def __init__(self):
        self.a = deque()
        self.b = deque()

    def gan(self):
        while len(self.a) > len(self.b):
            self.b.appendleft(self.a.pop())
        while len(self.b) > len(self.a) + 1:
            self.a.append(self.b.popleft())

    def pushFront(self, val: int) -> None:
        self.a.appendleft(val)
        self.gan()

    def pushMiddle(self, val: int) -> None:
        self.a.append(val)
        self.gan()

    def pushBack(self, val: int) -> None:
        self.b.append(val)
        self.gan()

    def popFront(self) -> int:
        if len(self.a) + len(self.b) == 0:
            return -1
        if len(self.a) == 0:
            return self.b.popleft()
        v = self.a.popleft()
        self.gan()
        return v

    def popMiddle(self) -> int:
        if len(self.a) + len(self.b) == 0:
            return -1
        if len(self.a) == len(self.b):
            return self.a.pop()
        else:
            return self.b.popleft()

    def popBack(self) -> int:
        if len(self.a) + len(self.b) == 0:
            return -1
        v = self.b.pop()
        self.gan()
        return v


# Your FrontMiddleBackQueue object will be instantiated and called as such:
# obj = FrontMiddleBackQueue()
# obj.pushFront(val)
# obj.pushMiddle(val)
# obj.pushBack(val)
# param_4 = obj.popFront()
# param_5 = obj.popMiddle()
# param_6 = obj.popBack()