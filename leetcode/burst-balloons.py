class Solution:
    def maxCoins(self, a: List[int]) -> int:
        n = len(a)
        a = [1] + a + [1]
        f = [[0 for j in range(n + 2)]for i in range(n + 2)]
        for l in range(2, n + 2):
            for i in range(0, n - l + 2):
                j = i + l
                for k in range(i + 1, j):
                    f[i][j] = max(f[i][j], f[i][k] + f[k][j] + a[i] * a[k] * a[j])
        return f[0][n + 1]
