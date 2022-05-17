class Solution:
    def maximizeSweetness(self, a: List[int], k: int) -> int:
        L = 0
        R = sum(a) + 1
        def ok(M):
            s = 0
            c = 0
            for i in a:
                s += i
                if s >= M:
                    s = 0
                    c += 1
            return c >= k + 1
        while L < R - 1:
            M = (L + R) // 2
            if ok(M):
                L = M
            else:
                R = M
        return L