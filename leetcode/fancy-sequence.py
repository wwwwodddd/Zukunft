p = 1000000007
class Fancy:

    def __init__(self):
        self.a = []
        self.i = 0
        self.m = 1

    def append(self, val: int) -> None:
        self.a.append((val - self.i) * pow(self.m, p - 2, p) % p)

    def addAll(self, inc: int) -> None:
        self.i = (self.i + inc) % p

    def multAll(self, m: int) -> None:
        self.i = self.i * m % p
        self.m = self.m * m % p

    def getIndex(self, idx: int) -> int:
        if idx < len(self.a):
            return (self.a[idx] * self.m + self.i) % p
        else:
            return -1

# Your Fancy object will be instantiated and called as such:
# obj = Fancy()
# obj.append(val)
# obj.addAll(inc)
# obj.multAll(m)
# param_4 = obj.getIndex(idx)