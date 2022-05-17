class Solution:
    def longestAwesome(self, s: str) -> int:
        g = {0:-1}
        z = b = 0
        for i in range(len(s)):
            b ^= 1 << int(s[i])
            if b in g:
                z = max(z, i - g[b])
            else:
                g[b] = i
            for j in range(10):
                z = max(z, i - g.get(b ^ (1 << j), i))
        return z