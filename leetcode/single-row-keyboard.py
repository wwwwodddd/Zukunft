class Solution:
    def calculateTime(self, s: str, a: str) -> int:
        z = 0
        p = 0
        for i in a:
            q = s.index(i)
            z += abs(p - q)
            p = q
        return z