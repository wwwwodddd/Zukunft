class Solution:
    def heightChecker(self, a: List[int]) -> int:
        b = sorted(a)
        return sum(x!=y for x,y in zip(a,b))