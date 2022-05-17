class Solution:
    def minCost(self, n: int, a: List[int]) -> int:
        a = sorted([0] + a + [n])
        m = len(a)
        f = [[0 for j in range(m)]for i in range(m)]
        for l in range(2, m):
            for i in range(0, m - l):
                j = i + l
                f[i][j] = f[i + 1][j]
                for k in range(i + 1, j):
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j])
                f[i][j] += a[j] - a[i]
        return f[0][m-1]