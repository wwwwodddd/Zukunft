class Solution:
    def maxWidthOfVerticalArea(self, a: List[List[int]]) -> int:
        a.sort()
        return max(y[0]-x[0]for x,y in zip(a,a[1:]))