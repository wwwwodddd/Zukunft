class Solution:
    def numberOfBoomerangs(self, a: List[List[int]]) -> int:
        z = 0
        for xi, yi in a:
            c = Counter()
            for xj, yj in a:
                d = (xi-xj)**2+(yi-yj)**2
                z += c[d]
                c[d] += 2
        return z