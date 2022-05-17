class Solution:
    def maxAreaOfIsland(self, a: List[List[int]]) -> int:
        n = len(a)
        m = len(a[0])
        z = 0
        def dfs(x, y):
            a[x][y] = 0
            c = 1
            for i, j in (x-1,y),(x+1,y),(x,y-1),(x,y+1):
                if 0<=i<n and 0<=j<m and a[i][j] == 1:
                    c += dfs(i, j)
            return c
        for i in range(n):
            for j in range(m):
                if a[i][j] == 1:
                    z = max(z, dfs(i, j))
        return z