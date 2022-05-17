class RandomizedSet:

    def __init__(self):
        self.a = []
        self.g = {}
    def insert(self, x: int) -> bool:
        if x in self.g:
            return False
        self.g[x] = len(self.a)
        self.a.append(x)
        return True

    def remove(self, x: int) -> bool:
        if x not in self.g:
            return False
        self.g[self.a[-1]] = self.g[x]
        self.a[self.g[x]] = self.a[-1]
        del self.g[x]
        self.a.pop()
        return True

    def getRandom(self) -> int:
        return choice(self.a)


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()