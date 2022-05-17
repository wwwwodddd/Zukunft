class Solution:
    def largestGoodInteger(self, s: str) -> str:
        z = ''
        for i in range(2, len(s)):
            if s[i] == s[i - 1] == s[i - 2]:
                z = max(z, s[i - 2: i + 1])
        return z