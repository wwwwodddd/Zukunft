class Solution:
    def baseNeg2(self, n: int) -> str:
        if n == 0:
            return '0'
        a = ''
        while n:
            a += str(n % 2)
            n -= n % 2
            n //= -2
        return a[::-1]