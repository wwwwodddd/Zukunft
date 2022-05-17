class Solution:
    def minDistance(self, s: str, t: str) -> int:
        n = len(s)
        m = len(t)
        f = [[9**9 for j in range(m+1)]for i in range(n+1)]
        f[0][0] = 0
        for i in range(n+1):
            for j in range(m+1):
                if i and j and s[i-1]==t[j-1]:
                    f[i][j] = f[i-1][j-1]
                if i:
                    f[i][j] = min(f[i][j], f[i-1][j] + 1)
                if j:
                    f[i][j] = min(f[i][j], f[i][j-1] + 1)
        return f[n][m]