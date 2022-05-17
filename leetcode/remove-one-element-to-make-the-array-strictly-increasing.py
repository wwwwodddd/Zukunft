class Solution:
    def canBeIncreasing(self, a: List[int]) -> bool:
        f, g = 0, 0
        for i in a:
            nf = ng = 1001
            if f < i:
                nf = i
            if g < i:
                ng = i
            ng = min(ng, f)
            f = nf
            g = ng
        return ng < 1001