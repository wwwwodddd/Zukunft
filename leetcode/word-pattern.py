class Solution:
    def wordPattern(self, s: str, a: str) -> bool:
        a = a.split()
        if len(s) != len(a):
            return False
        if len(set(s)) != len(set(a)):
            return False
        g = {}
        for i in range(len(s)):
            if a[i] not in g:
                g[a[i]] = s[i]
            elif g[a[i]] != s[i]:
                return False
        return True