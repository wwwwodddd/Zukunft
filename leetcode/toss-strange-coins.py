class Solution:
    def probabilityOfHeads(self, ps: List[float], t: int) -> float:
        f = [1.0]
        for p in ps:
            g = [0 for i in f + [0]]
            for j in range(len(f)):
                g[j + 1] += f[j] * p
                g[j] += f[j] * (1 - p)
            f = g
        return f[t]