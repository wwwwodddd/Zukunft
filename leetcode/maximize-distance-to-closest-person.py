class Solution:
    def maxDistToClosest(self, a: List[int]) -> int:
        l = 0
        r = 0
        n = len(a)
        while a[l] == 0:
            l += 1
        while a[n - 1 - r] == 0:
            r += 1
        z = 0
        c = 0
        for i in a:
            if i == 0:
                c += 1
                z = max(z, c)
            else:
                c = 0
        z = (z + 1) // 2
        return max(z, l, r)