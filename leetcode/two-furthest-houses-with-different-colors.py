class Solution:
    def maxDistance(self, a: List[int]) -> int:
        z = 0
        n = len(a)
        for i in range(n):
            if a[i] != a[0]:
                z = max(z, i)
            if a[i] != a[-1]:
                z = max(z, n - 1 - i)
        return z