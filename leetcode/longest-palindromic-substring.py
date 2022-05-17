class Solution:
    def longestPalindrome(self, s: str) -> str:
        z = ''
        s = '<' + s + '>'
        for i in range(1, len(s) - 1):
            j = 0
            while s[i - j] == s[i + j]:
                j += 1
                if len(z) < 2 * j - 1:
                    z = s[i - j + 1: i + j]
            j = 0
            while s[i - j - 1] == s[i + j]:
                j += 1
                if len(z) < 2 * j:
                    z = s[i - j: i + j]
        return z