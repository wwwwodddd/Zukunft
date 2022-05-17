class StockSpanner:

    def __init__(self):
        self.s = []

    def next(self, price: int) -> int:
        c = 1
        while len(self.s) > 0 and price >= self.s[-1][0]:
            c += self.s.pop()[1]
        self.s.append([price,c])
        return c


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)