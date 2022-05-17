class Solution:
    def waysToBuyPensPencils(self, t: int, x: int, y: int) -> int:
        z = 0
        for i in range(t // x + 1):
            z += (t - i * x) // y + 1
        return z