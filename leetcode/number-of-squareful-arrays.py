class Solution:
    def numSquarefulPerms(self, a: List[int]) -> int:
        def issqr(x):
            y = int(x ** 0.5)
            return y * y == x
        a.sort()
        n = len(a)
        f = [[0 for j in range(n)]for i in range(1 << n)]
        for i in range(n):
            if i == 0 or a[i] != a[i - 1]:
                f[1 << i][i] = 1
        z = 0
        for i in range(1 << n):
            for j in range(n):
                if i >> j & 1:
                    for k in range(n):
                        if ~i >> k & 1 and (k == 0 or a[k - 1] != a[k] or i >> (k - 1) & 1) and issqr(a[j] + a[k]):
                            f[i | 1 << k][k] += f[i][j]
                    if i == (1 << n) - 1:
                        z = (z + f[i][j])
        return z