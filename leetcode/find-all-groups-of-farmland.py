class Solution:
    def findFarmland(self, a: List[List[int]]) -> List[List[int]]:
        n = len(a)
        m = len(a[0])
        z = 0
        def dfs(x, y):
            nonlocal mnx, mxx, mny, mxy
            mnx = min(mnx, x)
            mxx = max(mxx, x)
            mny = min(mny, y)
            mxy = max(mxy, y)
            a[x][y] = 0
            c = 1
            for i, j in (x-1,y),(x+1,y),(x,y-1),(x,y+1):
                if 0<=i<n and 0<=j<m and a[i][j] == 1:
                    c += dfs(i, j)
            return c
        z = []
        for i in range(n):
            for j in range(m):
                if a[i][j] == 1:
                    mnx = mxx = i
                    mny = mxy = j
                    dfs(i, j)
                    z.append([mnx, mny, mxx, mxy])
        return z