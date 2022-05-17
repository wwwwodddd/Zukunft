class Solution:
    def minFallingPathSum(self, a: List[List[int]]) -> int:
        n = len(a)
        m = len(a[0])
        f = [[9**9 for j in range(m)]for i in range(n)]
        for j in range(m):
            f[0][j] = a[0][j]
        for i in range(1,n):
            mf = min(f[i-1])
            mfk = f[i-1].index(mf)
            for j in range(m):
                if j != mfk:
                    f[i][j] = mf + a[i][j]
                else:
                    for k in range(m):
                        if j!=k:
                            f[i][j]=min(f[i][j],f[i-1][k]+a[i][j])
        return min(f[-1])