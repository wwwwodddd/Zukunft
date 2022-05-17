class CustomStack:

    def __init__(self, maxSize: int):
        self.ms = maxSize
        self.s = []
        self.a = [0]

    def push(self, x: int) -> None:
        if len(self.s) < self.ms:
            self.s.append(x)
            self.a.append(0)

    def pop(self) -> int:
        if len(self.s) == 0:
            return -1
        self.a[-2] += self.a[-1]
        return self.s.pop() + self.a.pop()

    def increment(self, k: int, val: int) -> None:
        self.a[min(k, len(self.s))] += val


# Your CustomStack object will be instantiated and called as such:
# obj = CustomStack(maxSize)
# obj.push(x)
# param_2 = obj.pop()
# obj.increment(k,val)