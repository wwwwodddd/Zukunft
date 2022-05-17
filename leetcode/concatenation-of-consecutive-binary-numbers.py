class Solution:
    def concatenatedBinary(self, n: int) -> int:
        p = 1000000007
        z = 0
        b = 1
        for i in range(1, n + 1):
            while b <= i:
                b *= 2
            z = (z * b + i) % p
        return z