class Solution:
    def minProductSum(self, a: List[int], b: List[int]) -> int:
        a.sort()
        b.sort(reverse=True)
        return sum(x*y for x,y in zip(a,b))