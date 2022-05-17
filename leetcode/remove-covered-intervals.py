class Solution:
    def removeCoveredIntervals(self, a: List[List[int]]) -> int:
        a.sort(key=lambda x:(x[0], -x[1]))
        z = 0
        p = 0
        for l, r in a:
            if p < r:
                p = r
                z += 1
        return z