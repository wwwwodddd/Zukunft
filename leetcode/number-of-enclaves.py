class Solution:
    def numEnclaves(self, g: List[List[int]]) -> int:
        n = len(g)
        m = len(g[0])
        def dfs(x, y):
            g[x][y]=0
            for nx, ny in (x+1,y),(x-1,y),(x,y+1),(x,y-1):
                if 0<=nx<n and 0<=ny<m and g[nx][ny]==1:
                    dfs(nx, ny)
        for i in range(n):
            if g[i][0]==1:
                dfs(i,0)
            if g[i][m-1]==1:
                dfs(i,m-1)
        for i in range(m):
            if g[0][i]==1:
                dfs(0,i)
            if g[n-1][i]==1:
                dfs(n-1,i)
        return sum(i.count(1)for i in g)