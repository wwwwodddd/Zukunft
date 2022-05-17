class Solution:
    def maxAbsoluteSum(self, a: List[int]) -> int:
        s = t = z = 0
        for i in a:
            s = max(s, 0) + i
            t = min(t, 0) + i
            z = max(z, abs(s), abs(t))
        return z