class Solution:
    def equalSubstring(self, s: str, t: str, m: int) -> int:
        z = 0
        j = 0
        for i in range(len(s)):
            m -= abs(ord(s[i]) - ord(t[i]))
            while m < 0:
                m += abs(ord(s[j]) - ord(t[j]))
                j += 1
            z = max(z, i - j + 1)
        return z