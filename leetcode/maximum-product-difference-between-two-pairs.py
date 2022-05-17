class Solution:
    def maxProductDifference(self, a: List[int]) -> int:
        a.sort()
        return a[-1]*a[-2]-a[0]*a[1]