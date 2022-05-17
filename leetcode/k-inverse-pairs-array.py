class Solution:
    def kInversePairs(self, n: int, m: int) -> int:
        p = 1000000007
        f = [[0 for j in range(m+2)]for i in range(n+1)]
        for i in range(1,m+2):
            f[0][i] = 1
        for i in range(1,n+1):
            for j in range(m+1):
                f[i][j + 1] = (f[i][j] + f[i-1][j+1] - f[i-1][j+1-min(j+1,i)]) % p
        return (f[n][m + 1] - f[n][m]) % p