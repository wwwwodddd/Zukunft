class Solution:
    def strangePrinter(self, s: str) -> int:
        n = len(s)
        f = [[0 for j in range(n)]for i in range(n)]
        for i in range(n)[::-1]:
            f[i][i] = 1
            for j in range(i + 1, n):
                f[i][j] = f[i][j - 1] + (s[i] != s[j])
                for k in range(i, j):
                    f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j])
        return f[0][n - 1]