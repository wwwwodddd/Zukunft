class Solution:
    def maxUncrossedLines(self, s: List[int], t: List[int]) -> int:
        n = len(s)
        m = len(t)
        f = [[0 for j in range(m+1)]for i in range(n+1)]
        for i in range(1,n+1):
            for j in range(1,m+1):
                if s[i-1]==t[j-1]:
                    f[i][j] = f[i-1][j-1]+1
                else:
                    f[i][j] = max(f[i-1][j],f[i][j-1])
        return f[n][m]