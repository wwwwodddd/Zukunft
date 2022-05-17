class Solution:
    def knightDialer(self, n: int) -> int:
        p = 1000000007
        x0 = x1 = x2 = x4 = x5 = 1
        for i in range(1, n):
            x0, x1, x2, x4, x5 = x4 * 2 % p, (x2 + x4) % p, x1 * 2 % p, (x1 * 2 + x0) % p, 0
        return (x0 + x1 * 4 + x2 * 2 + x4 * 2 + x5) % p