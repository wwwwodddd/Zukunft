class Solution:
    def subdomainVisits(self, a: List[str]) -> List[str]:
        c = Counter()
        for s in a:
            r, d = s.split()
            r = int(r)
            while True:
                c[d] += r
                p = d.find('.')
                if p == -1:
                    break
                else:
                    d = d[p + 1:]
        z = []
        for i in c:
            z.append('%d %s' % (c[i], i))
        return z