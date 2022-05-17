class Solution:
    def numberOfWays(self, n: int) -> int:
        n //= 2
        p = 1000000007
        c = 1
        d = n + 1
        for i in range(n):
            c = c * (2 * n - i) % p
            d = d * (i + 1) % p
        return c * pow(d, p - 2, p) % p