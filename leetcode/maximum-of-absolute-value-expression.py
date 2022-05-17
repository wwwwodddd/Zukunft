class Solution:
    def maxAbsValExpr(self, a: List[int], b: List[int]) -> int:
        z = 0
        for x in 1,-1:
            for y in 1,-1:
                c = [i + x * a[i] + y * b[i] for i in range(len(a))]
                z = max(z, max(c) - min(c))
        return z