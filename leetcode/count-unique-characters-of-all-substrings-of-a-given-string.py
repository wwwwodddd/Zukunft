class Solution:
    def uniqueLetterString(self, s: str) -> int:
        f = Counter()
        g = Counter()
        z = 0
        for i in range(len(s)):
            f[s[i]] = g[s[i]]
            g[s[i]] = i + 1
            z += sum(g.values()) - sum(f.values())
        return z