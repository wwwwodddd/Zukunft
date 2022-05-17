class Solution:
    def minAreaRect(self, a: List[List[int]]) -> int:
        s = set()
        for x, y in a:
            s.add((x, y))
        z = 10**10
        for x1, y1 in a:
            for x2, y2 in a:
                if x1 < x2 and y1 < y2 and (x1, y2) in s and (x2, y1) in s:
                    z = min(z, (x2 - x1) * (y2 - y1))
        if z == 10**10:
            z = 0
        return z