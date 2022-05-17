class Solution:
    def sumSubseqWidths(self, a: List[int]) -> int:
        p = 1000000007
        a.sort()
        s = t = 0
        for i in a[::-1]:
            s = (s * 2 + i) % p
        for i in a:
            t = (t * 2 + i) % p
        return (s - t) % p