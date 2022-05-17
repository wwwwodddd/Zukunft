class Solution:
    def isRectangleOverlap(self, a: List[int], b: List[int]) -> bool:
        c = [max(a[0], b[0]), max(a[1], b[1]), min(a[2], b[2]), min(a[3], b[3])]
        return max(c[2] - c[0], 0) * max(c[3] - c[1], 0) > 0