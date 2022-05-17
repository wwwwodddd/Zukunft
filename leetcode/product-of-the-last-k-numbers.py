class ProductOfNumbers:

    def __init__(self):
        self.s = [1]

    def add(self, x: int) -> None:
        if x:
            self.s.append(self.s[-1] * x)
        else:
            self.s = [1]

    def getProduct(self, k: int) -> int:
        if k < len(self.s):
            return self.s[-1] // self.s[-k-1]
        else:
            return 0

# Your ProductOfNumbers object will be instantiated and called as such:
# obj = ProductOfNumbers()
# obj.add(num)
# param_2 = obj.getProduct(k)