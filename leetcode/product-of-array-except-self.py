class Solution:
    def productExceptSelf(self, a: List[int]) -> List[int]:
        n = len(a)
        f = [1 for i in range(n + 1)]
        g = [1 for i in range(n + 1)]
        for i in range(n):
            f[i + 1] = f[i] * a[i]
        for i in range(n)[::-1]:
            g[i] = g[i + 1] * a[i]
        return [f[i] * g[i + 1] for i in range(n)]