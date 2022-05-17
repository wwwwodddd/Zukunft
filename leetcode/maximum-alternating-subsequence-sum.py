class Solution:
    def maxAlternatingSum(self, a: List[int]) -> int:
        f = g = 0
        for i in a:
            f, g = max(f, g + i), max(g, f - i)
        return f