class Solution:
    def brightestPosition(self, a: List[List[int]]) -> int:
        g = Counter()
        for x, y in a:
            g[x - y] += 1
            g[x + y + 1] -= 1
        b = sorted(g.items())
        s = 0
        z = 0
        p = 0
        for x, y in b:
            s += y
            if z < s:
                z = s
                p = x
        return p