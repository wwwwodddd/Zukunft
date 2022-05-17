class Solution:
    def maximumBeauty(self, a: List[int]) -> int:
        n = len(a)
        s = [0 for i in range(n + 1)]
        for i in range(n):
            s[i + 1] = s[i] + max(a[i], 0)
        g = {}
        z = -1e9
        for i in range(len(a)):
            if a[i] in g:
                z = max(z, s[i] - s[g[a[i]] + 1] + 2 * a[i])
            else:
                g[a[i]] = i
        return z