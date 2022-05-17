class Solution:
    def restoreMatrix(self, r: List[int], c: List[int]) -> List[List[int]]:
        n = len(r)
        m = len(c)
        a = [[0 for j in range(m)]for i in range(n)]
        x = y = 0
        while x < n and y < m:
            a[x][y] = min(r[x], c[y])
            r[x] -= a[x][y]
            c[y] -= a[x][y]
            while x < n and r[x] == 0:
                x += 1
            while y < m and c[y] == 0:
                y += 1
        return a