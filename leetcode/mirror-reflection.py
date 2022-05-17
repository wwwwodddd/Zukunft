class Solution:
    def mirrorReflection(self, p: int, q: int) -> int:
        g = gcd(p, q)
        return 1 - p // g % 2 + q // g % 2