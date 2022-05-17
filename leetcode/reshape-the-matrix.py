class Solution:
    def matrixReshape(self, a: List[List[int]], r: int, c: int) -> List[List[int]]:
        n = len(a)
        m = len(a[0])
        if r * c != n * m:
            return a
        b = [[0 for j in range(c)]for i in range(r)]
        for i in range(r):
            for j in range(c):
                x, y = (i * c + j) // m, (i * c + j) % m
                b[i][j] = a[x][y]
        return b