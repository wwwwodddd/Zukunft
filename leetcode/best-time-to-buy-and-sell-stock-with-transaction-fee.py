class Solution:
    def maxProfit(self, a: List[int], k: int) -> int:
        f, g = 0, -9**9
        for i in a:
            f, g = max(f, g + i), max(g, f - i - k)
        return f