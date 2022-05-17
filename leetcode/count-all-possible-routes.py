class Solution:
    def countRoutes(self, a: List[int], s: int, t: int, m: int) -> int:
        p = 1000000007
        n = len(a)
        f = [[0 for j in range(len(a))]for i in range(m+1)]
        f[0][s] = 1
        for i in range(1, m + 1):
            for j in range(n):
                for k in range(n):
                    if j != k and i >= abs(a[j] - a[k]):
                        f[i][j] = (f[i][j] + f[i - abs(a[j] - a[k])][k]) % p
        z = 0
        for i in range(m + 1):
            z = (z + f[i][t]) % p
        return z