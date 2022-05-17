class Solution:
    def maxValueOfCoins(self, p: List[List[int]], k: int) -> int:
        f = [0] * (k + 1)
        for a in p:
            g = f[:]
            s = 0
            for i in range(len(a)):
                s += a[i]
                for j in range(i + 1, k + 1):
                    g[j] = max(g[j], f[j - (i + 1)] + s)
            f = g
        return f[-1]