class Solution:
    def maximalSquare(self, a: List[List[str]]) -> int:
        n = len(a)
        m = len(a[0])
        f = [[0 for j in range(m)]for i in range(n)]
        z = 0
        for i in range(n):
            for j in range(m):
                if a[i][j]=='1':
                    if i and j:
                        f[i][j] = min(f[i-1][j-1],f[i-1][j],f[i][j-1])+1
                    else:
                        f[i][j] = 1
                    z = max(z, f[i][j])
        return z**2