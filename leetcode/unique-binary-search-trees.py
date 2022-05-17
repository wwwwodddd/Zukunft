class Solution:
    def numTrees(self, n: int) -> int:
        z = 1
        for i in range(n):
            z = z * (2 * n - i) // (i + 1)
        z //= n + 1
        return z