class Solution:
    def getFood(self, a: List[List[str]]) -> int:
        q = deque()
        n = len(a)
        m = len(a[0])
        d = [[-1 for j in range(m)]for i in range(n)]
        for i in range(n):
            for j in range(m):
                if a[i][j] == '*':
                    q.append((i, j))
                    d[i][j] = 0
        def nei(x, y):
            return 0 <= x < n and 0 <= y < m
        while q:
            x, y = q.popleft()
            if a[x][y] == '#':
                return d[x][y]
            for nx, ny in (x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1):
                if nei(nx, ny) and d[nx][ny] == -1 and a[nx][ny] != 'X':
                    d[nx][ny] = d[x][y] + 1
                    q.append((nx, ny))
        return -1