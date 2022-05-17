class Solution:
    def digitsCount(self, d: int, l: int, h: int) -> int:
        def F(n, d):
            z = 0
            t = 1
            while t < n:
                z += n // 10 // t * t
                if n // t % 10 > d:
                    z += t
                elif n // t % 10 == d:
                    z += n % t
                if d == 0:
                    z -= t
                t *= 10
            return z
        return F(h + 1, d) - F(l, d)