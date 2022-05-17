class Solution:
    def generateAbbreviations(self, s: str) -> List[str]:
        z = []
        n = len(s)
        for i in range(1 << n):
            u = ''
            c = 0
            for j in range(n):
                if i >> j & 1:
                    if c > 0:
                        u += str(c)
                        c = 0
                    u += s[j]
                else:
                    c += 1
            if c > 0:
                u += str(c)
                c = 0
            z.append(u)
        return z