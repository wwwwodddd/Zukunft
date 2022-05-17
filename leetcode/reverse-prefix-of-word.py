class Solution:
    def reversePrefix(self, s: str, c: str) -> str:
        if c not in s:
            return s
        p = s.index(c)
        return s[:p+1][::-1]+s[p+1:]