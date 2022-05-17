class Solution:
    def checkZeroOnes(self, s: str) -> bool:
        z0 = z1 = c0 = c1 = 0
        for i in s:
            if i=='1':
                c1 += 1
                z1 = max(z1, c1)
                c0 = 0
            else:
                c0 += 1
                z0 = max(z0, c0)
                c1 = 0
        return z1 > z0