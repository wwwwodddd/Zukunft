class Solution:
    def mctFromLeafValues(self, a: List[int]) -> int:
        n = len(a)
        f = [[0 for j in range(n)]for i in range(n)]
        g = [[0 for j in range(n)]for i in range(n)]
        for i in range(n):
            g[i][i] = a[i]
        for l in range(1, n):
            for i in range(n - l):
                j = i + l
                f[i][j] = 9**9
                for k in range(i, j):
                    f[i][j] = min(f[i][j], f[i][k] + f[k+1][j] + g[i][k] * g[k+1][j])
                g[i][j] = max(g[i][j-1], a[j])
        return f[0][n-1]
