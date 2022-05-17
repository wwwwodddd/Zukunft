class Solution:
    def brokenCalc(self, s: int, t: int) -> int:
        c = 0
        while t > s:
            if t & 1:
                t += 1
                c += 1
            else:
                t >>= 1
                c += 1
        return s - t + c