class Solution:
    def maxProfit(self, a: List[int]) -> int:
        z = 0
        for i in range(1,len(a)):
            z += max(a[i]-a[i-1],0)
        return z