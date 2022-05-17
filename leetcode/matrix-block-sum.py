class Solution:
    def matrixBlockSum(self, a: List[List[int]], k: int) -> List[List[int]]:
        n = len(a)
        m = len(a[0])
        s = [[0 for j in range(m+1)]for i in range(n+1)]
        for i in range(n):
            for j in range(m):
                s[i + 1][j + 1] = s[i + 1][j] + s[i][j + 1] - s[i][j] + a[i][j]
        z = [[0 for j in range(m)]for i in range(n)]
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                i2 = min(i + k, n)
                j2 = min(j + k, m)
                i1 = max(i - k - 1, 0)
                j1 = max(j - k - 1, 0)
                z[i - 1][j - 1] = s[i2][j2] - s[i1][j2] - s[i2][j1] + s[i1][j1]
        return z