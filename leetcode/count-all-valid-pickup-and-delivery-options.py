class Solution:
    def countOrders(self, n: int) -> int:
        p = 1000000007
        f = [[0 for j in range(n+1)]for i in range(n+1)]
        f[0][0] = 1
        for i in range(n+1):
            for j in range(i+1):
                if i < n:
                    f[i + 1][j] = (f[i + 1][j] + f[i][j] * (n - i)) % p
                if j < i:
                    f[i][j + 1] = (f[i][j + 1] + f[i][j] * (i - j)) % p                    
        return f[n][n]