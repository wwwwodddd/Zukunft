class Solution:
    def numTilings(self, n: int) -> int:
        f = [0 for i in range(n + 1)]
        g = [0 for i in range(n + 1)]
        p = 1000000007
        f[0] = 1
        f[1] = 1
        g[1] = 1
        for i in range(2, n + 1):
            f[i] = (f[i-1] + f[i-2] + 2*g[i-2]) % p
            g[i] = (g[i-1] + f[i-1]) % p
        return f[n]