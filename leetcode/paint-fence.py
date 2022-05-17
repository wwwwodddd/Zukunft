class Solution:
    def numWays(self, n: int, k: int) -> int:
        f, g = k, 0
        for i in range(1, n):
            f, g = (k - 1) * f + (k - 1) * g, f
        return f + g