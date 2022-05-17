class Solution:
    def perfectMenu(self, a: List[int], c: List[List[int]], d: List[List[int]], limit: int) -> int:
        n = len(c)
        z = -1
        for i in range(2 ** n):
            b = a.copy()
            d0 = 0
            d1 = 0
            for j in range(n):
                if i >> j & 1:
                    for k in range(len(b)):
                        b[k] -= c[j][k]
                    d0 += d[j][0]
                    d1 += d[j][1]
            if min(b) >= 0 and d1 >= limit:
                z = max(z, d0)
        return z