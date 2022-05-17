class Solution:
    def numSquares(self, n: int) -> int:
        f = [i for i in range(n + 1)]
        i = 1
        while i * i <= n:
            for j in range(i * i, n + 1):
                f[j] = min(f[j], f[j - i * i] + 1)
            i += 1
        return f[n]