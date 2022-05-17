class Solution:
    def solve(self, g: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        n = len(g)
        m = len(g[0])
        for i in range(n):
            for j in range(m):
                if g[i][j] == 'O':
                    g[i][j] = ' '
        def dfs(x, y):
            g[x][y]='O'
            for nx, ny in (x+1,y),(x-1,y),(x,y+1),(x,y-1):
                if 0<=nx<n and 0<=ny<m and g[nx][ny]==' ':
                    dfs(nx, ny)
        for i in range(n):
            if g[i][0]==' ':
                dfs(i,0)
            if g[i][m-1]==' ':
                dfs(i,m-1)
        for i in range(m):
            if g[0][i]==' ':
                dfs(0,i)
            if g[n-1][i]==' ':
                dfs(n-1,i)
        for i in range(n):
            for j in range(m):
                if g[i][j]==' ':
                    g[i][j]='X'
        return g