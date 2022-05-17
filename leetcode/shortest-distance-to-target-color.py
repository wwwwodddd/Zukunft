class Solution:
    def shortestDistanceColor(self, a: List[int], q: List[List[int]]) -> List[int]:
        n = len(a)
        f = [[1e9, 1e9, 1e9, 1e9] for i in range(n + 1)]
        g = [[1e9, 1e9, 1e9, 1e9] for i in range(n + 1)]
        for i in range(n):
            f[i] = f[i - 1].copy()
            f[i][a[i]] = i
        for i in range(n)[::-1]:
            g[i] = g[i + 1].copy()
            g[i][a[i]] = i
        z = []
        for x, y in q:
            u = min(abs(x - f[x][y]), abs(x - g[x][y]))
            if u > n:
                u = -1
            z.append(u)
        return z