class Solution:
    def minDominoRotations(self, a: List[int], b: List[int]) -> int:
        n = len(a)
        def zuo(x, a, b):
            c = 0
            for i in range(n):
                if a[i] == x:
                    pass
                elif b[i] == x:
                    c += 1
                else:
                    return n + 1
            return c
        z = min(zuo(a[0], a, b), zuo(a[0], b, a), zuo(b[0], a, b), zuo(b[0], b, a))
        if z == n + 1:
            z = -1
        return z