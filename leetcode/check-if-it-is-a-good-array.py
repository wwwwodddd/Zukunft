class Solution:
    def isGoodArray(self, a: List[int]) -> bool:
        return gcd(*a) == 1