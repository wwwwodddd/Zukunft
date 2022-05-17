class Solution:
    def findNthDigit(self, n: int) -> int:
        n -= 1
        d = 1
        while n > d * 9 * 10 ** (d - 1):
            n -= d * 9 * 10 ** (d - 1)
            d += 1
        return str(n // d + 10 ** (d - 1))[n % d]