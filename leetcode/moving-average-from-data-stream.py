class MovingAverage:

    def __init__(self, n: int):
        self.n = n
        self.q = deque()
        self.s = 0

    def next(self, v: int) -> float:
        self.q.append(v)
        self.s += v
        if len(self.q) > self.n:
            self.s -= self.q.popleft()
        return self.s / len(self.q)

# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param_1 = obj.next(val)