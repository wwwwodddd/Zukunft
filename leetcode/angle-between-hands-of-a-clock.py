class Solution:
    def angleClock(self, h: int, m: int) -> float:
        d = (30 * h - 5.5 * m) % 360
        return min(d, 360 - d)