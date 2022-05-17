class Solution:
    def countQuadruples(self, a: str, b: str) -> int:
        z = 1e9
        c = 0
        for i in set(a) & set(b):
            d = a.index(i) - b.rindex(i)
            if z > d:
                z = d
                c = 1
            elif z == d:
                c += 1
        return c