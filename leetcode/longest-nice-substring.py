class Solution:
    def longestNiceSubstring(self, s: str) -> str:
        z = ''
        for i in range(len(s)):
            x = y = 0
            for j in range(i, len(s)):
                if s[j].islower():
                    x |= 1 << ord(s[j]) - 97
                else:
                    y |= 1 << ord(s[j]) - 65
                if x == y:
                    if len(z) < j - i + 1:
                        z = s[i: j + 1]
        return z