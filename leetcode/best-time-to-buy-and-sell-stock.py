class Solution:
    def maxProfit(self, a: List[int]) -> int:
        mn = 99999
        z = 0
        for i in a:
            mn = min(mn, i)
            z = max(z, i - mn)
        return z