class Solution:
    def getMoneyAmount(self, n: int) -> int:
        f = [[0 for i in range(n+2)]for j in range(n+2)]
        for l in range(2,n+1):
            for i in range(1,n-l+2):
                j = i+l-1
                t = 9**9
                for k in range(i,j+1):
                    t = min(t, max(f[i][k-1],f[k+1][j])+k)
                f[i][j] = t
        return f[1][n]