class Solution:
    def maximumElementAfterDecrementingAndRearranging(self, a: List[int]) -> int:
        a.sort()
        a[0] = 1
        for i in range(1, len(a)):
            a[i] = min(a[i], a[i - 1] + 1)
        return a[-1]