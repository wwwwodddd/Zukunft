class Solution:
    def maxSumTwoNoOverlap(self, a: List[int], x: int, y: int) -> int:
        n = len(a)
        s = [0]
        for i in a:
            s.append(s[-1] + i)
        f = [0 for i in range(n + 1)]
        g = [0 for i in range(n + 1)]
        for i in range(x, n + 1):
            f[i] = max(f[i - 1], s[i] - s[i - x])
        for i in range(0, n + 1 - y)[::-1]:
            g[i] = max(g[i + 1], s[i + y] - s[i])
        z = max(f[i] + g[i] for i in range(n + 1))
        x, y = y, x
        for i in range(x, n + 1):
            f[i] = max(f[i - 1], s[i] - s[i - x])
        for i in range(0, n + 1 - y)[::-1]:
            g[i] = max(g[i + 1], s[i + y] - s[i])
        z = max(z, max(f[i] + g[i] for i in range(n + 1)))
        return z