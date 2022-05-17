class Solution:
    def longestIncreasingPath(self, a: List[List[int]]) -> int:
        n = len(a)
        m = len(a[0])
        f = [[-1 for j in range(m)]for i in range(n)]
        def dfs(x, y):
            if f[x][y] != -1:
                return f[x][y]
            f[x][y] = 1
            for nx,ny in (x+1,y),(x-1,y),(x,y+1),(x,y-1):
                if 0<=nx<n and 0<=ny<m and a[nx][ny]>a[x][y]:
                    f[x][y] = max(f[x][y], dfs(nx,ny) + 1)
            return f[x][y]
        for i in range(n):
            for j in range(m):
                dfs(i, j)
        return max(map(max, f))