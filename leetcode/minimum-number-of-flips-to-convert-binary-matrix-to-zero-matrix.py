class Solution:
    def minFlips(self, a: List[List[int]]) -> int:
        o = copy.deepcopy(a)
        n = len(a)
        m = len(a[0])
        def nei(x, y):
            return 0 <= x < n and 0 <= y < m
        b = [[0 for j in range(m)] for i in range(n)]
        dx = [1, -1, 0, 0, 0]
        dy = [0, 0, 1, -1, 0]
        z = n * m + 1
        for k in range(1 << n * m):
            a = copy.deepcopy(o)
            for i in range(n):
                for j in range(m):
                    b[i][j] = (k >> (i * m + j) & 1)
            for i in range(n):
                for j in range(m):
                    for d in range(5):
                        nx = i + dx[d]
                        ny = j + dy[d]
                        if nei(nx, ny):
                            a[i][j] ^= b[nx][ny]
            c = 0
            for i in range(n):
                for j in range(m):
                    c += a[i][j]
            if c == 0:
                for i in range(n):
                    for j in range(m):
                        c += b[i][j]
                z = min(z, c)
        if z == n * m + 1:
            z = -1
        return z