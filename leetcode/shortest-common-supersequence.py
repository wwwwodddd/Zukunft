class Solution:
    def shortestCommonSupersequence(self, s: str, t: str) -> str:
        n = len(s)
        m = len(t)
        f = [[9**9 for j in range(m+1)]for i in range(n+1)]
        g = [['' for j in range(m+1)]for i in range(n+1)]
        p = [[(0, 0) for j in range(m+1)]for i in range(n+1)]
        f[0][0] = 0
        for i in range(n+1):
            for j in range(m+1):
                if i and j and s[i-1]==t[j-1]:
                    f[i][j] = f[i-1][j-1] + 1
                    g[i][j] = s[i-1]
                    p[i][j] = (i-1, j-1)
                if i and f[i][j] > f[i-1][j] + 1:
                    f[i][j] = f[i-1][j] + 1
                    g[i][j] = s[i-1]
                    p[i][j] = (i-1, j)
                if j and f[i][j] > f[i][j-1] + 1:
                    f[i][j] = f[i][j-1] + 1
                    g[i][j] = t[j-1]
                    p[i][j] = (i, j-1)
        z = ''
        x, y = n, m
        while x > 0 or y > 0:
            z += g[x][y]
            x, y = p[x][y]
        return z[::-1]