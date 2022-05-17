class Solution:
    def minimumTime(self, a: List[int], m: int) -> int:
        L = 0
        R = 10 ** 18
        while L < R - 1:
            M = (L + R) // 2
            c = sum(M // i for i in a)
            if c >= m:
                R = M
            else:
                L = M
        return R