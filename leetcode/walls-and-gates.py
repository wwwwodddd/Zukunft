class Solution:
    def wallsAndGates(self, d: List[List[int]]) -> None:
        """
        Do not return anything, modify rooms in-place instead.
        """
        n = len(d)
        m = len(d[0])
        q = deque()
        for i in range(n):
            for j in range(m):
                if d[i][j] == 0:
                    q.append((i, j))
        def nei(x, y):
            return 0 <= x < n and 0 <= y < m
        while q:
            x, y = q.popleft()
            for nx, ny in (x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1):
                if nei(nx, ny) and d[nx][ny] == 2147483647:
                    d[nx][ny] = d[x][y] + 1
                    q.append((nx, ny))
        return d