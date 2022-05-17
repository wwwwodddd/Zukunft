class Solution:
    def sumOfBeauties(self, a: List[int]) -> int:
        n = len(a)
        f = a[:]
        g = a[:]
        for i in range(1, n):
            f[i] = max(f[i], f[i - 1])
        for i in range(n - 1)[::-1]:
            g[i] = min(g[i], g[i + 1])
        z = 0
        for i in range(1, n - 1):
            if f[i - 1] < a[i] < g[i + 1]:
                z += 2
            elif a[i - 1] < a[i] < a[i + 1]:
                z += 1
        return z