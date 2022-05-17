class Solution:
    def minFlips(self, s: str) -> int:
        s = '0' + s
        z = 0
        for i in range(1, len(s)):
            if s[i] != s[i - 1]:
                z += 1
        return z