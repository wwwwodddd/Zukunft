class Solution:
    def groupStrings(self, a: List[str]) -> List[List[str]]:
        def F(s):
            t = ''
            d = ord(s[0]) - 97
            for i in s:
                t += chr((ord(i) - 97 - d) % 26 + 97)
            return t
        g = defaultdict(list)
        for i in a:
            g[F(i)].append(i)
        return list(g.values())