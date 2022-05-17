class Solution:
    def threeSumMulti(self, a: List[int], m: int) -> int:
        p = 1000000007
        f = [[0 for j in range(m+1)]for i in range(4)]
        f[0][0] = 1
        for k in a:
            for i in range(1,4)[::-1]:
                for j in range(k,m+1)[::-1]:
                    f[i][j] = (f[i][j] + f[i-1][j-k]) % p
        return f[3][m]