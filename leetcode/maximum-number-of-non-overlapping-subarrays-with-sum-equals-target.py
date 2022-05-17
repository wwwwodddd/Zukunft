class Solution:
    def maxNonOverlapping(self, a: List[int], t: int) -> int:
        g = {0}
        s = 0
        c = 0
        for i in a:
            s += i
            if s - t in g:
                g = {0}
                s = 0
                c += 1
            else:
                g.add(s)
        return c