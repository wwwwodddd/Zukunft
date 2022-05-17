class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        def dui(t):
            return len(t) > 0 and str(int(t)) == t and 0 <= int(t) < 256
        z = []
        for i in range(len(s)):
            if dui(s[i:]):
                for j in range(i):
                    if dui(s[j:i]):
                        for k in range(1, j):
                            if dui(s[k:j]) and dui(s[:k]):
                                z.append('%s.%s.%s.%s' % (s[:k], s[k:j], s[j:i], s[i:]))
        return z