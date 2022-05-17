class Solution:

    def __init__(self, n: int, m: int):
        self.n = n
        self.m = m
        self.c = n * m
        self.g = {}

    def flip(self) -> List[int]:
        p = randrange(self.c)
        q = self.g.get(p, p)
        self.c -= 1
        self.g[p] = self.g.get(self.c, self.c)
        return [q // self.m, q % self.m]

    def reset(self) -> None:
        self.g = {}
        self.c = self.n * self.m

# Your Solution object will be instantiated and called as such:
# obj = Solution(m, n)
# param_1 = obj.flip()
# obj.reset()