class Solution:
    def findShortestSubArray(self, a: List[int]) -> int:
        f = {}
        c = Counter()
        n = len(a)
        y = z = 0
        for i in range(n):
            if a[i] not in f:
                f[a[i]] = i
            c[a[i]] += 1
            if y < c[a[i]] or y == c[a[i]] and z > i - f[a[i]]:
                y = c[a[i]]
                z = i - f[a[i]]
        return z + 1