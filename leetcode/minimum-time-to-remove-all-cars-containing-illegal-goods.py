class Solution:
    def minimumTime(self, s: str) -> int:
        f = 0
        z = len(s)
        for i in range(len(s)):
            if s[i] == '1':
                f = min(i + 1, f + 2)
            z = min(z, f + len(s) - i - 1)
        return z