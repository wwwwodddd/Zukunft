class Solution:
    def distinctSubseqII(self, s: str) -> int:
        p = 1000000007
        f = [0] * 26
        for i in s:
            f[ord(i) - 97] = (sum(f) + 1) % p
        return sum(f) % p