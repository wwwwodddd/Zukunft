class Solution:
    def spiralOrder(self, a: List[List[int]]) -> List[int]:
        n = len(a)
        m = len(a[0])
        v = [[0 for j in range(m)]for i in range(n)]
        dx = [0, 1, 0, -1]
        dy = [1, 0, -1, 0]
        x, y = 0, -1
        z = []
        while len(z) < n * m:
            for i in range(4):
                while 0 <= x + dx[i] < n and 0 <= y + dy[i] < m and v[x + dx[i]][y + dy[i]] == 0:
                    x += dx[i]
                    y += dy[i]
                    z.append(a[x][y])
                    v[x][y] = 1
        return z