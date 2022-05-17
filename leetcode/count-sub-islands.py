class Solution:
    def countSubIslands(self, g1: List[List[int]], g2: List[List[int]]) -> int:
        n = len(g1)
        m = len(g1[0])
        c = 0
        def dfs2(x, y):
            nonlocal c
            c &= g1[x][y]
            g2[x][y] = 0
            for nx, ny in (x+1,y),(x-1,y),(x,y+1),(x,y-1):
                if 0<=nx<n and 0<=ny<m and g2[nx][ny]==1:
                    dfs2(nx, ny)
        z = 0
        for i in range(n):
            for j in range(m):
                if g2[i][j]==1:
                    c = 1
                    dfs2(i,j)
                    if c > 0:
                        z += 1
        return z