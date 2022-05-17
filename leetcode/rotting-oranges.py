class Solution:
    def orangesRotting(self, a: List[List[int]]) -> int:
        q = deque()
        n = len(a)
        m = len(a[0])
        d = [[-1 for j in range(m)]for i in range(n)]
        for i in range(n):
            for j in range(m):
                if a[i][j] == 2:
                    d[i][j] = 0
                    q.append((i, j))
        z = 0
        while len(q):
            x, y = q.popleft()
            for dx, dy in (0, 1), (0, -1), (1, 0), (-1, 0):
                nx = x + dx
                ny = y + dy
                if 0 <= nx < n and 0 <= ny < m and a[nx][ny] != 0:
                    if d[nx][ny] == -1:
                        d[nx][ny] = d[x][y] + 1
                        z = max(z, d[nx][ny])
                        q.append((nx, ny))
        for i in range(n):
            for j in range(m):
                if a[i][j] == 1 and d[i][j] == -1:
                    return -1
        return z