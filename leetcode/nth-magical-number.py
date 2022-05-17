class Solution:
    def nthMagicalNumber(self, n: int, a: int, b: int) -> int:
        l = a * b // gcd(a, b)
        def zuo(m):
            return m//a + m//b - m//l
        L = 0
        R = 10**18
        while L < R - 1:
            M = (L + R) // 2
            if zuo(M) < n:
                L = M
            else:
                R = M
        return R % 1000000007