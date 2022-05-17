class Solution:
    def isConvex(self, p: List[List[int]]) -> bool:
        def xm(a, b, c):
            return (b[0] - a[0]) * (c[1] - a[1]) - (b[1] - a[1]) * (c[0] - a[0])
        z = 0
        for i in range(len(p)):
            z += xm([0, 0], p[i - 1], p[i])
        if z < 0:
            p = p[::-1]
        for i in range(len(p)):
            if xm(p[i - 2], p[i - 1], p[i]) < 0:
                return False
        return True