class Solution:
    def findClosestNumber(self, a: List[int]) -> int:
        z = max(a)
        for i in a:
            if abs(i) < abs(z):
                z = i
            elif abs(i) == abs(z) and i > z:
                z = i
        return z