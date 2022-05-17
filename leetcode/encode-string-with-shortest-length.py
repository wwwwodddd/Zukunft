class Solution:
    @lru_cache(None)
    def encode(self, s: str) -> str:
        if len(s) < 5:
            return s
        z = s
        for i in range(1, len(s)):
            if len(s) % i == 0 and s[:-i] == s[i:]:
                z = min(z, '%d[%s]' % (len(s) // i, self.encode(s[:i])), key=len)
            z = min(z, self.encode(s[:i]) + self.encode(s[i:]), key=len)
        return z