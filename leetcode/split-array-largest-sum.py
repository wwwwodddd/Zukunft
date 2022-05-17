class Solution:
    def splitArray(self, a: List[int], m: int) -> int:
        L = 0
        R = sum(a)
        def ok(M):
            s = M
            c = 0
            for i in a:
                if s + i > M:
                    s = 0
                    c += 1
                s += i
                if s > M:
                    return False
            return c <= m
        while L < R - 1:
            M = (L + R) // 2
            if ok(M):
                R = M
            else:
                L = M
        return R