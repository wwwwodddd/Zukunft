class Solution:

    def __init__(self, w: List[int]):
        self.s = w
        for i in range(1, len(self.s)):
            self.s[i] += self.s[i - 1]

    def pickIndex(self) -> int:
        return bisect_left(self.s, randint(1, self.s[-1]))

# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()