class Solution:
    def ambiguousCoordinates(self, s: str) -> List[str]:
        def gan(s):
            if s[0] != '0':
                z = [s]
                if s[-1] != '0':
                    for i in range(1, len(s)):
                        z.append(s[:i] + '.' + s[i:])
                return z
            elif len(s) == 1:
                return [s]
            elif s[-1] != '0':
                return [s[:1] + '.' + s[1:]]
            else:
                return []
        s = s[1:-1]
        z = []
        for i in range(1, len(s)):
            for j in gan(s[:i]):
                for k in gan(s[i:]):
                    z.append('(%s, %s)' % (j, k))
        return z