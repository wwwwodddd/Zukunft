class Solution:
    def maxProduct(self, a: List[int]) -> int:
        a.sort()
        return (a[-1]-1)*(a[-2]-1)