class Solution:
    def numDecodings(self, s: str) -> int:
        f = [0 for i in range(len(s) + 1)]
        f[0] = 1
        for i in range(len(s)):
            if s[i] != '0':
                f[i + 1] += f[i]
            if i > 0 and s[i - 1] != '0' and int(s[i - 1:i + 1]) < 27:
                f[i + 1] += f[i - 1]
        return f[len(s)]