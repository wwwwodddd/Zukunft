class Solution:
    def longestWPI(self, a: List[int]) -> int:
        g = {}
        s = 0
        z = 0
        for i in range(len(a)):
            if a[i] > 8:
                s += 1
            else:
                s -= 1
            if s > 0:
                z = max(z, i + 1)
            else:
                z = max(z, i - g.get(s - 1, i))
            if s not in g:
                g[s] = i
        return z