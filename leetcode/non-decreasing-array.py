class Solution:
    def checkPossibility(self, a: List[int]) -> bool:
        f, g = -1000001, -1000001
        for i in a:
            nf = ng = 1000001
            if f <= i:
                nf = i
            if g <= i:
                ng = i
            ng = min(ng, f)
            f = nf
            g = ng
        return ng < 1000001