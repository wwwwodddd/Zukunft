class Solution:
    def findAndReplacePattern(self, a: List[str], p: str) -> List[str]:
        def die(p):
            g = {}
            a = []
            for i in range(len(p)):
                if p[i] not in g:
                    g[p[i]] = i
                a.append(g[p[i]])
            return a
        p = die(p)
        z = []
        for i in a:
            if die(i) == p:
                z.append(i)
        return z