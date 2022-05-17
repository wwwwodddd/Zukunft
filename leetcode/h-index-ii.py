class Solution:
    def hIndex(self, a: List[int]) -> int:
        L = 0
        R = len(a) + 1
        while L < R - 1:
            M = (L + R) // 2
            if a[-M] >= M:
                L = M
            else:
                R = M
        return L