class Solution:
    def checkRecord(self, n: int) -> int:
        p = 1000000007
        f = [[0, 0, 0, 0, 0, 0] for i in range(n + 1)]
        f[0][0] = 1
        for i in range(n):
            f[i + 1][0] = (f[i][0] + f[i][2] + f[i][4]) % p
            f[i + 1][1] = (f[i][0] + f[i][1] + f[i][2] + f[i][3] + f[i][4] + f[i][5]) % p
            f[i + 1][2] = (f[i][0]) % p
            f[i + 1][3] = (f[i][1]) % p
            f[i + 1][4] = (f[i][2]) % p
            f[i + 1][5] = (f[i][3]) % p
        return sum(f[n]) % p