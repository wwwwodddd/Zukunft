class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        n = 101
        f = [[0 for j in range(n)]for i in range(n)]
        f[0][0] = poured
        for i in range(n - 1):
            for j in range(i + 1):
                if f[i][j] > 1:
                    f[i + 1][j] += (f[i][j] - 1) / 2
                    f[i + 1][j + 1] += (f[i][j] - 1) / 2
                    f[i][j] = 1
        return f[query_row][query_glass]