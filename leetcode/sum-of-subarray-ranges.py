class Solution:
    def subArrayRanges(self, a: List[int]) -> int:
        z = 0
        for i in range(len(a)):
            mn = mx = a[i]
            for j in range(i, len(a)):
                mn = min(mn, a[j])
                mx = max(mx, a[j])
                z += mx - mn
        return z