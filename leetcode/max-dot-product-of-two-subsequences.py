class Solution:
    def maxDotProduct(self, a: List[int], b: List[int]) -> int:
        n = len(a)
        m = len(b)
        f = [[-10**10 for j in range(m+1)]for i in range(n+1)]
        for i in range(1, n+1):
            for j in range(1, m+1):
                f[i][j] = max(f[i][j-1],f[i-1][j],a[i-1]*b[j-1]+max(0,f[i-1][j-1]))
        return f[n][m]