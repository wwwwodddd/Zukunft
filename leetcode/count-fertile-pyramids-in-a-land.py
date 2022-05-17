class Solution:
    def countPyramids(self, a: List[List[int]]) -> int:
        n = len(a)
        m = len(a[0])
        f = [[0 for j in range(m)]for i in range(n)]
        z = 0
        for i in range(n):
            for j in range(m):
                if a[i][j]:
                    if i==0:
                        f[i][j]=1
                    else:
                        t=f[i-1][j]
                        if j>0:
                            t=min(t,f[i-1][j-1])
                        else:
                            t=0
                        if j<m-1:
                            t=min(t,f[i-1][j+1])
                        else:
                            t=0
                        f[i][j]=t+1
                z+=max(f[i][j]-1,0)
        f = [[0 for j in range(m)]for i in range(n)]
        a=a[::-1]
        for i in range(n):
            for j in range(m):
                if a[i][j]:
                    if i==0:
                        f[i][j]=1
                    else:
                        t=f[i-1][j]
                        if j>0:
                            t=min(t,f[i-1][j-1])
                        else:
                            t=0
                        if j<m-1:
                            t=min(t,f[i-1][j+1])
                        else:
                            t=0
                        f[i][j]=t+1
                z+=max(f[i][j]-1,0)
        return z