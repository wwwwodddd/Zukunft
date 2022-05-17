class Solution:
    def numRookCaptures(self, a: List[List[str]]) -> int:
        x = -1
        y = -1
        n = len(a)
        m = len(a[0])
        for i in range(n):
            for j in range(m):
                if a[i][j] == 'R':
                    x = i
                    y = j
        def nei(x, y):
            return 0 <= x < n and 0 <= y < m
        z = 0
        for dx, dy in (0, 1), (1, 0), (0, -1), (-1, 0):
            cx, cy = x, y
            while True:
                cx += dx
                cy += dy
                if not nei(cx, cy):
                    break
                if a[cx][cy] == 'p':
                    z += 1
                    break
                if a[cx][cy] != '.':
                    break
        return z