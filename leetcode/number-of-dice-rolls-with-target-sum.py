class Solution:
    def numRollsToTarget(self, n: int, m: int, t: int) -> int:
        p = 1000000007
        f = [0 for i in range(1020)]
        f[0] = 1
        for i in range(n):
            g = [0 for i in range(1020)]
            for j in range(i * m + 1):
                for k in range(1, m + 1):
                    g[j + k] = (g[j + k] + f[j]) % p
            f = g
        return f[t]

        