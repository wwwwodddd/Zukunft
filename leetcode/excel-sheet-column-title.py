class Solution:
    def convertToTitle(self, n: int) -> str:
        m = 0
        while n >= 26 ** m:
            n -= 26 ** m
            m += 1
        z = ''
        for i in range(m):
            z += chr(65 + n // 26 ** (m - 1 - i) % 26)
        return z