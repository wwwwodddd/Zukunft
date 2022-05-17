class Solution:
    def largestAltitude(self, a: List[int]) -> int:
        z = 0
        s = 0
        for i in a:
            s += i
            z = max(z, s)
        return z