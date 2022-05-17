class Solution:
    def superEggDrop(self, k: int, n: int) -> int:
        f = [[0 for j in range(n + 1)]for i in range(k + 1)]
        for i in range(k + 1):
            f[i][0] = 1
        for j in range(n + 1):
            f[0][j] = 1
        for i in range(1, k + 1):
            for j in range(1, n + 1):
                f[i][j] = f[i-1][j-1] + f[i][j-1]
        for i in range(1, n + 1):
            if f[k][i] > n:
                return i
