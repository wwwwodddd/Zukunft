class Solution:
    def countSpecialSubsequences(self, a: List[int]) -> int:
        f = g = h = 0
        p = 1000000007
        for i in a:
            if i == 0:
                f = (f * 2 + 1) % p
            elif i == 1:
                g = (g * 2 + f) % p
            else:
                h = (h * 2 + g) % p
        return h