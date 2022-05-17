class Solution:
    def maximumAlternatingSubarraySum(self, a: List[int]) -> int:
        z = f = g = -1e9
        for i in a:
            f, g = max(i, g + i), f - i
            z = max(z, f, g)
        return z