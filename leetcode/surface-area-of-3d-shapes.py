class Solution:
    def surfaceArea(self, a: List[List[int]]) -> int:
        z = 0
        n = len(a)
        m = len(a[0])
        for i in range(n):
            for j in range(m):
                if a[i][j] > 0:
                    z += 2
        for i in range(n):
            z += a[i][0] + a[i][-1]
            for j in range(1,m):
                z += abs(a[i][j]-a[i][j-1])
        for j in range(m):
            z += a[0][j] + a[-1][j]
            for i in range(1,n):
                z += abs(a[i][j]-a[i-1][j])
        return z