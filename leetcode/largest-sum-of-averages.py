class Solution:
    def largestSumOfAverages(self, a: List[int], m: int) -> float:
        n = len(a)
        f = [[0 for j in range(n + 1)]for i in range(m + 1)]
        for j in range(1, n + 1):
            f[1][j] = sum(a[:j]) / j
        for i in range(2, m + 1):
            for j in range(1, n + 1):
                for k in range(0, j):
                    f[i][j] = max(f[i][j], f[i-1][k] + sum(a[k:j])/(j-k))
        return f[m][n]