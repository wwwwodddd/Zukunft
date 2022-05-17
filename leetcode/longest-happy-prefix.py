class Solution:
    def longestPrefix(self, s: str) -> str:
        p = [0]
        u = 0
        for i in range(1, len(s)):
            while u and s[u] != s[i]:
                u = p[u - 1]
            if s[u] == s[i]:
                u += 1
            p.append(u)
        return s[:p[-1]]