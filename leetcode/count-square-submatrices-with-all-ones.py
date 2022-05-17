class Solution:
    def countSquares(self, a: List[List[int]]) -> int:
        n=len(a)
        m=len(a[0])
        f=[[0 for j in range(m)]for i in range(n)]
        z=0
        for i in range(n):
            for j in range(m):
                if a[i][j]:
                    if i==0 or j==0:
                        f[i][j]=1
                    else:
                        f[i][j]=min(f[i-1][j],f[i][j-1],f[i-1][j-1])+1
                z+=f[i][j]
        return z