class OrderedStream:

    def __init__(self, n: int):
        self.a = ['' for i in range(n+1)]
        self.i = 1
        self.n = n

    def insert(self, idKey: int, value: str) -> List[str]:
        self.a[idKey] = value
        r = []
        while self.i <= self.n and self.a[self.i]:
            r.append(self.a[self.i])
            self.i += 1
        return r


# Your OrderedStream object will be instantiated and called as such:
# obj = OrderedStream(n)
# param_1 = obj.insert(idKey,value)