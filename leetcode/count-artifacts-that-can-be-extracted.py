class Solution:
    def digArtifacts(self, n: int, a: List[List[int]], d: List[List[int]]) -> int:
        g = [[0 for j in range(n)]for i in range(n)]
        for x, y in d:
            g[x][y] = 1
        z = 0
        for x1, y1, x2, y2 in a:
            s = 0
            for i in range(x1, x2 + 1):
                for j in range(y1, y2 + 1):
                    s += g[i][j]
            if s == (x2 - x1 + 1) * (y2 - y1 + 1):
                z += 1
        return z