class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        a = [[0 for j in range(n)]for i in range(n)]
        c = 0
        dx = [0, 1, 0, -1]
        dy = [1, 0, -1, 0]
        x, y = 0, -1
        while c < n * n:
            for i in range(4):
                while 0 <= x + dx[i] < n and 0 <= y + dy[i] < n and a[x + dx[i]][y + dy[i]] == 0:
                    x += dx[i]
                    y += dy[i]
                    c += 1
                    a[x][y] = c
        return a