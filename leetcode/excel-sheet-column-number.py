class Solution:
    def titleToNumber(self, s: str) -> int:
        z = 1
        for i in range(1, len(s)):
            z += 26 ** i
        for i in range(len(s)):
            z += 26 ** (len(s) - 1 - i) * (ord(s[i]) - 65)
        return z