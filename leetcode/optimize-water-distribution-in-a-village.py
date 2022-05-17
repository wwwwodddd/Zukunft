class Solution:
    def minCostToSupplyWater(self, n: int, w: List[int], p: List[List[int]]) -> int:
        f = list(range(n + 1))
        e = []
        for i in range(1, n + 1):
            e.append((w[i - 1], 0, i))
        for x, y, c in p:
            e.append((c, x, y))
        e.sort()
        z = 0
        def F(x):
            if f[x] == x:
                return x
            f[x] = F(f[x])
            return f[x]
        for c, x, y in e:
            if F(x) != F(y):
                f[F(x)] = F(y)
                z += c
        return z
                