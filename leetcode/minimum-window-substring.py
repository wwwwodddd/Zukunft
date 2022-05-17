class Solution:
    def minWindow(self, s: str, t: str) -> str:
        z = ' ' * (len(s) + 1)
        j = 0
        c = Counter()
        d = 0
        for i in t:
            if c[i] == 0:
                d += 1
            c[i] -= 1
        for i in range(len(s)):
            while j < len(s) and d > 0:
                c[s[j]] += 1
                if c[s[j]] == 0:
                    d -= 1
                j += 1
            if d == 0:
                if len(z) > j - i:
                    z = s[i:j]
            else:
                break
            if c[s[i]] == 0:
                d += 1
            c[s[i]] -= 1
        if len(z) == len(s) + 1:
            z = ''
        return z