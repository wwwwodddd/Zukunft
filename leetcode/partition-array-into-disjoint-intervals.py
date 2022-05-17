class Solution:
    def partitionDisjoint(self, a: List[int]) -> int:
        n = len(a)
        f = a[:]
        g = a[:]
        for i in range(1, n):
            f[i] = max(f[i], f[i - 1])
        for i in range(n - 1)[::-1]:
            g[i] = min(g[i], g[i + 1])
        for i in range(1, n):
            if f[i - 1] <= g[i]:
                return i