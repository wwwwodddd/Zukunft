class Solution:
    def findTheLongestSubstring(self, s: str) -> int:
        g = {0:-1}
        z = b = 0
        for i in range(len(s)):
            if s[i] in 'aeiou':
                b ^= 1 << 'aeiou'.index(s[i])
            if b in g:
                z = max(z, i - g[b])
            else:
                g[b] = i
        return z