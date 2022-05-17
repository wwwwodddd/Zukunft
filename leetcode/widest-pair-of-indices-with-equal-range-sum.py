class Solution:
    def widestPairOfIndices(self, a: List[int], b: List[int]) -> int:
        s = 0
        g = {}
        g[0] = -1
        z = 0
        for i in range(len(a)):
            s += a[i] - b[i]
            if s in g:
                z = max(z, i - g[s])
            else:
                g[s] = i
        return z