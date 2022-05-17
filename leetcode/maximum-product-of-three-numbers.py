class Solution:
    def maximumProduct(self, a: List[int]) -> int:
        a.sort()
        return max(a[-1] * a[-2] * a[-3], a[-1] * a[0] * a[1])