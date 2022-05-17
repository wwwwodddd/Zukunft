class Solution:
    def findPeakElement(self, a: List[int]) -> int:
        a.append(-10**10)
        L = -1
        R = len(a)
        while L < R - 2:
            M = (L + R) // 2
            if a[M] < a[M + 1]:
                L = M
            else:
                R = M + 1
        return (L + R) // 2