class Solution:
    def updateMatrix(self, a: List[List[int]]) -> List[List[int]]:
        q = deque()
        n = len(a)
        m = len(a[0])
        d = [[-1 for j in range(m)]for i in range(n)]
        for i in range(n):
            for j in range(m):
                if a[i][j] == 0:
                    d[i][j] = 0
                    q.append((i, j))
        while len(q):
            x, y = q.popleft()
            for dx, dy in (0, 1), (0, -1), (1, 0), (-1, 0):
                nx = x + dx
                ny = y + dy
                if 0 <= nx < n and 0 <= ny < m:
                    if d[nx][ny] == -1:
                        d[nx][ny] = d[x][y] + 1
                        q.append((nx, ny))
        return d