class Solution:
    def knightProbability(self, n: int, m: int, x: int, y: int) -> float:
        f = [[[0.0 for j in range(n)]for i in range(n)] for k in range(m+1)]
        f[0][x][y]=1.0
        for k in range(m):
            for i in range(n):
                for j in range(n):
                    if f[k][i][j]:
                        for di, dj in (1,2),(2,1),(-1,2),(2,-1),(1,-2),(-2,1),(-1,-2),(-2,-1):
                            ni=i+di
                            nj=j+dj
                            if 0<=ni<n and 0<=nj<n:
                                f[k+1][ni][nj]+=f[k][i][j]/8
        return sum(map(sum,f[m]))