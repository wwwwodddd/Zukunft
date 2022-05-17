class Solution:
    def maxEqualRowsAfterFlips(self, a: List[List[int]]) -> int:
        c = Counter()
        for r in a:
            r = [i ^ r[0] for i in r]
            c[tuple(r)] += 1
        return max(c.values())