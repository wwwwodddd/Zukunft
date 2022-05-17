class Solution:
    def minimumDistance(self, s: str) -> int:
        f = {}
        for i in range(26):
            for j in range(26):
                f[i, j] = 0
        def D(x, y):
            return abs(x // 6 - y // 6) + abs(x % 6 - y % 6)
        for i in s:
            i = ord(i) - 65
            g = defaultdict(lambda:1e9)
            for x, y in f:
                g[x, i] = min(g[x, i], f[x, y] + D(i, y))
                g[i, y] = min(g[i, y], f[x, y] + D(x, i))
            f = g
        return min(f.values())