class Solution:
    def longestMountain(self, a: List[int]) -> int:
        n = len(a)
        f = [0 for i in range(n)]
        for i in range(1, n):
            if a[i] > a[i - 1]:
                f[i] = f[i - 1] + 1
            else:
                f[i] = 0
        g = [0 for i in range(n)]
        for i in range(n - 1)[::-1]:
            if a[i] > a[i + 1]:
                g[i] = g[i + 1] + 1
            else:
                g[i] = 0
        z = 0
        for i in range(n):
            if f[i] > 0 < g[i]:
                z = max(z, f[i] + 1 + g[i])
        return z