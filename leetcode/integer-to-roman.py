class Solution:
    def intToRoman(self, n: int) -> str:
        r = ''
        for t, a, b, c in[[1000,'M','',''],[100,'C','D','M'],[10,'X','L','C'],[1,'I','V','X']]:
            d = n // t % 10
            if d < 4:
                r += a * d
            elif d == 4:
                r += a + b
            elif d < 9:
                r += b + (d - 5) * a
            else:
                r += a + c
        return r