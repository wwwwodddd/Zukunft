class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        def zuo(s):
            a = {}
            z = []
            for i in range(len(s)):
                if s[i] not in a:
                    a[s[i]] = i
                z.append(a[s[i]])
            return z
        return zuo(s) == zuo(t)