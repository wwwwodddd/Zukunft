class Solution:
    def maxArea(self, a: List[int]) -> int:
        l = 0
        r = len(a) - 1
        z = 0
        while l < r:
            z = max(z, (r - l) * min(a[l], a[r]))
            if a[l] < a[r]:
                l += 1
            else:
                r -= 1
        return z