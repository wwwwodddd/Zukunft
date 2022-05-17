class Solution:
    def minimumFinishTime(self, tires: List[List[int]], c: int, n: int) -> int:
        f = [10 ** 18 for i in range(20)]
        f[0] = 0
        for x, y in tires:
            s = 0
            for i in range(1, 20):
                s += x * y ** (i - 1)
                f[i] = min(f[i], s)
                if s > 10 ** 6:
                    break
        g = [10 ** 18 for i in range(n + 1)]
        g[0] = 0
        for i in range(1, n + 1):
            for j in range(1, 20):
                if i >= j:
                    g[i] = min(g[i], g[i - j] + f[j] + c)
        return g[n] - c