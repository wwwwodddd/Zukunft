class Solution:
    def maximumSum(self, a: List[int]) -> int:
        z = f = g = a[0]
        for i in a[1:]:
            f, g = max(f, 0) + i, max(f, g + i)
            z = max(z, f, g)
        return z