class Solution:
    def minCostII(self, a: List[List[int]]) -> int:
        f = a[0]
        for i in range(1, len(a)):
            g = [10000 for j in a[i]]
            for j in range(len(a[i])):
                for k in range(len(a[i])):
                    if j != k:
                        g[j] = min(g[j], f[k] + a[i][j])
            f = g
        return min(f)