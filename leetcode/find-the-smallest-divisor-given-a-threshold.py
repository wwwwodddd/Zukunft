class Solution:
    def smallestDivisor(self, a: List[int], n: int) -> int:
        L = 0
        R = max(a)
        while L < R - 1:
            M = (L + R) // 2
            if sum((i + M - 1) // M for i in a) <= n:
                R = M
            else:
                L = M
        return R