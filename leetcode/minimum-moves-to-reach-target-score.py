class Solution:
    def minMoves(self, n: int, m: int) -> int:
        z = n
        for i in range(m + 1):
            if 1 << i <= n:
                d = n - (1 << i)
                c = i + (d >> i)
                for j in range(i):
                    if d >> j & 1:
                        c += 1
                z = min(z, c)
            else:
                break
        return z