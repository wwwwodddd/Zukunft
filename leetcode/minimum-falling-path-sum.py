class Solution:
    def minFallingPathSum(self, a: List[List[int]]) -> int:
        n = len(a)
        m = len(a[0])
        for i in range(1, n):
            for j in range(m):
                f = a[i - 1][j]
                if j > 0:
                    f = min(f, a[i - 1][j - 1])
                if j + 1 < m:
                    f = min(f, a[i - 1][j + 1])
                a[i][j] += f
        return min(a[-1])
