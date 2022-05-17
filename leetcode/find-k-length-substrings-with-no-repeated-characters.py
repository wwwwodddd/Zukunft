class Solution:
    def numKLenSubstrNoRepeats(self, s: str, k: int) -> int:
        z = 0
        g = {}
        l = -1
        for i in range(len(s)):
            if s[i] in g:
                l = max(l, g[s[i]])
            g[s[i]] = i
            if i - l >= k:
                z += 1
        return z