class MedianFinder:
    def __init__(self):
        self.p = []
        self.q = []

    def addNum(self, x: int) -> None:
        if len(self.p) == len(self.q):
            heapq.heappush(self.p, -heapq.heappushpop(self.q, -x))
        else:
            heapq.heappush(self.q, -heapq.heappushpop(self.p, x))

    def findMedian(self) -> float:
        if len(self.p) == len(self.q):
            return (self.p[0] - self.q[0]) / 2
        else:
            return self.p[0]

# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()