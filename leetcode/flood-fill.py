class Solution:
    def floodFill(self, g: List[List[int]], sr: int, sc: int, nc: int) -> List[List[int]]:
        n = len(g)
        m = len(g[0])
        oc = g[sr][sc]
        if oc == nc:
            return g
        def dfs(x, y):
            g[x][y]=nc
            for nx, ny in (x+1,y),(x-1,y),(x,y+1),(x,y-1):
                if 0<=nx<n and 0<=ny<m and g[nx][ny]==oc:
                    dfs(nx, ny)
        dfs(sr,sc)
        return g