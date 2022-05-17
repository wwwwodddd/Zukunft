class Solution:
    def maxVacationDays(self, a: List[List[int]], d: List[List[int]]) -> int:
        n = len(d)
        m = len(d[0])
        f = [-1e9 for i in range(n)]
        f[0] = 0
        for i in range(m):
            g = f[:]
            for j in range(n):
                for k in range(n):
                    if a[j][k]:
                        g[k] = max(g[k], f[j])
            for j in range(n):
                g[j] += d[j][i]
            f = g
        return max(f)