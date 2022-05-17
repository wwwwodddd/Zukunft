class Solution:
    def countDigitOne(self, n: int) -> int:
        n += 1
        z = 0
        for i in range(10):
            z += n // 10 ** (i + 1) * 10 ** i
            if n // 10 ** i % 10 > 1:
                z += 10 ** i
            elif n // 10 ** i % 10 == 1:
                z += n % 10 ** i
        return z