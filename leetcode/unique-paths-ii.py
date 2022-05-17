class Solution:
    def uniquePathsWithObstacles(self, s: List[List[int]]) -> int:
        n = len(s)
        m = len(s[0])
        f = [[0 for j in range(m)]for i in range(n)]
        for i in range(n):
            for j in range(m):
                if s[i][j]:
                    continue
                if i==0 and j==0:
                    f[i][j] = 1
                else:
                    if i > 0:
                        f[i][j] += f[i - 1][j]
                    if j > 0:
                        f[i][j] += f[i][j - 1]
        return f[n - 1][m - 1]