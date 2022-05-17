class Solution:
    def new21Game(self, n: int, k: int, m: int) -> float:
        f = [0.0 for i in range(m + n + 1)]
        for i in range(m + n)[::-1]:
            if i <= n:
                if i >= k:
                    f[i] = 1.0
                else:
                    f[i] = (f[i + 1] - f[i + m + 1]) / m
            f[i] += f[i + 1]
        return f[0] - f[1]