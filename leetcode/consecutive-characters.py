class Solution:
    def maxPower(self, s: str) -> int:
        l = ''
        c = 0
        z = 0
        for i in s:
            if l != i:
                l = i
                c = 0
            c += 1
            z = max(z, c)
        return z