class Solution:
    def minimumCardPickup(self, a: List[int]) -> int:
        g = {}
        n = len(a)
        z = n + 1
        for i in range(n):
            if a[i] in g:
                z = min(z, i - g[a[i]] + 1)
            g[a[i]] = i
        if z == n + 1:
            z = -1
        return z