class HitCounter:

    def __init__(self):
        self.q = deque()

    def hit(self, t: int) -> None:
        self.q.append(t)

    def getHits(self, t: int) -> int:
        while len(self.q) and self.q[0] <= t - 300:
            self.q.popleft()
        return len(self.q)


# Your HitCounter object will be instantiated and called as such:
# obj = HitCounter()
# obj.hit(timestamp)
# param_2 = obj.getHits(timestamp)