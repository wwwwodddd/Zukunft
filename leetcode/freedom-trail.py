class Solution:
    def findRotateSteps(self, s: str, t: str) -> int:
        f = [10000] * len(s)
        f[0] = 0
        for i in t:
            g = [10000] * len(s)
            for j in range(len(s)):
                if s[j] == i:
                    for k in range(len(s)):
                        g[j] = min(g[j], f[k] + min(abs(j - k), len(s) - abs(j - k)) + 1)
            f = g
        return min(f)