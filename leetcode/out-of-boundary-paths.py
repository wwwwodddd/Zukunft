class Solution:
    def findPaths(self, n: int, m: int, maxMove: int, startRow: int, startColumn: int) -> int:
        p = 1000000007
        z = 0
        f = [[0 for j in range(m)]for i in range(n)]
        f[startRow][startColumn] = 1
        for k in range(maxMove):
            g = [[0 for j in range(m)]for i in range(n)]
            for i in range(n):
                for j in range(m):
                    for x,y in (i+1,j),(i-1,j),(i,j+1),(i,j-1):
                        if 0<=x<n and 0<=y<m:
                            g[x][y] = (g[x][y] + f[i][j]) % p
                        else:
                            z = (z + f[i][j]) % p
            f = g
        return z