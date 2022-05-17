class Solution:
    def findMaxLength(self, a: List[int]) -> int:
        z = s = 0
        g = {s: -1}
        for i in range(len(a)):
            if a[i]:
                s += 1
            else:
                s -= 1
            if s in g:
                z = max(z, i - g[s])
            else:
                g[s] = i
        return z