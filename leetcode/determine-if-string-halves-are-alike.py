class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        c = 0
        n = len(s) // 2
        for i in 'aeoiuAEIOU':
            c += s[:n].count(i) - s[n:].count(i)
        return c == 0