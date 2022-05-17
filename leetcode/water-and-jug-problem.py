class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        return z <= x + y and z % gcd(x, y) == 0