class Solution:
    def findTargetSumWays(self, a: List[int], t: int) -> int:
        f = Counter([0])
        for i in a:
            g = Counter()
            for j in f:
                g[j + i] += f[j]
                g[j - i] += f[j]
            f = g
        return g[t]