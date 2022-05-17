class Solution:
    def maxProfit(self, a: List[int]) -> int:
        f, g, h = 0, -9**9, 0
        for i in a:
            f, g, h = max(f, h), max(g, f - i), g + i
        return max(f, h)