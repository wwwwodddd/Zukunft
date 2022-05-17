class Solution:
    def minInsertions(self, s: str) -> int:
        n = len(s)
        f = [[0 for j in range(n)]for i in range(n)]
        for l in range(1, n):
            for i in range(0, n - l):
                j = i + l
                if s[i] == s[j]:
                    f[i][j] = f[i + 1][j - 1]
                else:
                    f[i][j] = min(f[i + 1][j], f[i][j - 1]) + 1
        return f[0][n - 1]