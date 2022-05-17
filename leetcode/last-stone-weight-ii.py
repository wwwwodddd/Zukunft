class Solution:
    def lastStoneWeightII(self, a: List[int]) -> int:
        f = set([0])
        for i in a:
            g = set()
            for j in f:
                g.add(j + i)
                g.add(j - i)
            f = g
        return min(i for i in f if i >= 0)