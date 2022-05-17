class Solution:
    def findSmallestRegion(self, a: List[List[str]], x: str, y: str) -> str:
        f = {}
        for b in a:
            for i in range(1, len(b)):
                f[b[i]] = b[0]
        s = {x}
        while x in f:
            x = f[x]
            s.add(x)
        while y not in s:
            y = f[y]
        return y