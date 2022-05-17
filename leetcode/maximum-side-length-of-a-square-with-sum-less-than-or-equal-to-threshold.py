class Solution:
    def maxSideLength(self, a: List[List[int]], t: int) -> int:
        n = len(a)
        m = len(a[0])
        s = [[0 for j in range(m+1)]for i in range(n+1)]
        for i in range(n):
            for j in range(m):
                s[i + 1][j + 1] = s[i + 1][j] + s[i][j + 1] - s[i][j] + a[i][j]
        z = 0
        for i in range(n):
            for j in range(m):
                for k in range(z + 1, min(n - i, m - j) + 1):
                    if s[i + k][j + k] - s[i + k][j] - s[i][j + k] + s[i][j] <= t:
                        z = max(z, k)
                    else:
                        break
        return z