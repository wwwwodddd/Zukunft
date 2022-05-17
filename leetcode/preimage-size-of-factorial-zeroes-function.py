class Solution:
    def preimageSizeFZF(self, k: int) -> int:
        def kan(n):
            s = 0
            while n > 0:
                n //= 5
                s += n
            return s
        def zuo(x):
            L = -1
            R = 10**10
            while L < R - 1:
                M = (L + R) // 2
                if kan(M) < x:
                    L = M
                else:
                    R = M
            return R
        return zuo(k + 1) - zuo(k)