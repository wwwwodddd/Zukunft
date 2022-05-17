class Solution:
    def peakIndexInMountainArray(self, a: List[int]) -> int:
        L = 0
        R = len(a) - 1
        while L < R - 1:
            M = (L + R) // 2
            if a[M - 1] < a[M] and a[M] > a[M + 1]:
                return M
            if a[M - 1] < a[M] < a[M + 1]:
                L = M
            else:
                R = M