class Solution:
    def maxSumAfterOperation(self, a: List[int]) -> int:
        z = 0
        f = 0
        g = 0
        for i in a:
            g = max(g + i, f + i * i, 0)
            f = max(f + i, 0)
            z = max(z, g)
        return z