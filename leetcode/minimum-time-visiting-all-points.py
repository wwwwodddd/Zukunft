class Solution:
    def minTimeToVisitAllPoints(self, p: List[List[int]]) -> int:
        return sum(max(abs(a[0]-b[0]),abs(a[1]-b[1]))for a,b in zip(p,p[1:]))