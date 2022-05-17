class Solution:
    def cherryPickup(self, a: List[List[int]]) -> int:
        n = len(a)
        for i in range(n):
            for j in range(n):
                if a[i][j] == -1:
                    a[i][j] = -10000
        f = [[[-10000 for k in range(n + 1)]for j in range(n + 1)]for i in range(2 * n)]
        f[0][0][0] = a[0][0]
        for i in range(1, 2 * n - 1):
            for x1 in range(n):
                for x2 in range(n):
                    y1 = i - x1
                    y2 = i - x2
                    if 0 <= y1 < n and 0 <= y2 < n:
                        f[i][x1][x2] = max(f[i - 1][x1][x2], f[i - 1][x1][x2 - 1], f[i - 1][x1 - 1][x2], f[i - 1][x1 - 1][x2 - 1])
                        f[i][x1][x2] += a[x1][y1]
                        if x1 != x2:
                            f[i][x1][x2] += a[x2][y2]
        return max(f[2 * n - 2][n - 1][n - 1], 0)