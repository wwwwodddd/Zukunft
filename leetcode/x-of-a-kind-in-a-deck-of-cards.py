class Solution:
    def hasGroupsSizeX(self, a: List[int]) -> bool:
        return gcd(*Counter(a).values()) > 1