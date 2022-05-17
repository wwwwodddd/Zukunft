class Solution:
    def countGoodRectangles(self, a: List[List[int]]) -> int:
        a = list(map(min, a))
        return a.count(max(a))