class Solution:
    def maxDistance(self, a: List[List[int]]) -> int:
        q = deque()
        n = len(a)
        m = len(a[0])
        d = [[-1 for j in range(m)]for i in range(n)]
        def nei(x, y):
            return 0 <= x < n and 0 <= y < m
        for i in range(n):
            for j in range(m):
                if a[i][j] == 1:
                    d[i][j] = 0
                    q.append((i, j))
        z = -1
        while q:
            x, y = q.popleft()
            if d[x][y] != 0:
                z = max(z, d[x][y])
            for nx, ny in (x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1):
                if nei(nx, ny) and d[nx][ny] == -1:
                    d[nx][ny] = d[x][y] + 1
                    q.append((nx, ny))
        return z