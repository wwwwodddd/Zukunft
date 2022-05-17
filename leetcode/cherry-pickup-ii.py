class Solution:
    def cherryPickup(self, a: List[List[int]]) -> int:
        n = len(a)
        m = len(a[0])
        f = [[[-9**9 for k in range(m)]for j in range(m)]for i in range(n)]
        f[0][0][m-1] = a[0][0] + a[0][m-1]
        for i in range(n-1):
            for j in range(m):
                for k in range(j+1,m):
                    for nj in range(max(j-1,0),min(j+2,m)):
                        for nk in range(max(k-1,0),min(k+2,m)):
                            if nj<nk:
                                f[i+1][nj][nk]=max(f[i+1][nj][nk],f[i][j][k]+a[i+1][nj]+a[i+1][nk])
        return max(max(b)for b in f[n-1])
