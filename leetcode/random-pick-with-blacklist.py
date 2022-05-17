class Solution:

    def __init__(self, n: int, a: List[int]):
        self.g = {}
        for i in sorted(a)[::-1]:
            n -= 1
            self.g[i] = self.g.get(n, n)
        self.n = n

    def pick(self) -> int:
        x = randrange(self.n)
        return self.g.get(x, x)


# Your Solution object will be instantiated and called as such:
# obj = Solution(n, blacklist)
# param_1 = obj.pick()