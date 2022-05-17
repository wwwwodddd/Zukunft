class Solution:
    def maxA(self, n: int) -> int:
        f = [i for i in range(n + 1)]
        for i in range(n + 1):
            for j in range(i - 2):
                f[i] = max(f[i], f[j] * (i - 1 - j))
        return f[n]