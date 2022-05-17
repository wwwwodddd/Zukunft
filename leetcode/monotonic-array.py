class Solution:
    def isMonotonic(self, a: List[int]) -> bool:
        return a==sorted(a) or a==sorted(a,reverse=True)