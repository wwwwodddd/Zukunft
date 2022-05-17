class Solution:
    def findKthNumber(self, m: int, n: int, k: int) -> int:
        L = 0
        R = n * m
        while L < R - 1:
            M = (L + R) // 2
            s = 0
            for i in range(1, n + 1):
                s += min(M // i, m)
            if s < k:
                L = M
            else:
                R = M
        return R