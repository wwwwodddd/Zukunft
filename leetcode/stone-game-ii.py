class Solution:
    def stoneGameII(self, a: List[int]) -> int:
        n = len(a)
        f = [[-9**9 for j in range(n+1)]for i in range(n+1)]
        for i in range(n + 1):
            f[n][i] = 0
        for i in range(n)[::-1]:
            for j in range(1, n + 1):
                s = 0
                for k in range(i, min(n, i + 2 * j)):
                    s += a[k]
                    f[i][j] = max(f[i][j], s - f[k + 1][max(j, k - i + 1)])
        return (sum(a) + f[0][1]) // 2