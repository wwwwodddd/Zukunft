class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        n -= 1
        m -= 1
        n += m
        r = 1
        for i in range(m):
            r = r * (n - i) // (i + 1)
        return r