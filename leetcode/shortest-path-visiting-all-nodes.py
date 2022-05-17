class Solution:
    def shortestPathLength(self, g: List[List[int]]) -> int:
        n = len(g)
        a = [[n for j in range(n)]for i in range(n)]
        for i in range(n):
            for j in g[i]:
                a[i][j] = 1
        for k in range(n):
            for i in range(n):
                for j in range(n):
                    a[i][j] = min(a[i][j], a[i][k] + a[k][j])
        f = [[999 for j in range(n)]for i in range(1 << n)]
        for i in range(n):
            f[1 << i][i] = 0
        for i in range(1 << n):
            for j in range(n):
                if i >> j & 1:
                    for k in range(n):
                        if ~i >> k & 1:
                            f[i | 1 << k][k] = min(f[i | 1 << k][k], f[i][j] + a[j][k])
        return min(f[-1])