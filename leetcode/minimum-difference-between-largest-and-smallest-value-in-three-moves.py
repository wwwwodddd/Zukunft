class Solution:
    def minDifference(self, a: List[int]) -> int:
        a.sort()
        if len(a) < 4:
            return 0
        return min(a[-1] - a[3], a[-2] - a[2], a[-3] - a[1], a[-4] - a[0])