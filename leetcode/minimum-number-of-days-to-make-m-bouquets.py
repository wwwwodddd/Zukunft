class Solution:
    def minDays(self, a: List[int], m: int, k: int) -> int:
        L = min(a) - 1
        R = max(a) + 1
        while L < R - 1:
            M = (L + R) // 2
            c = s = 0
            for i in a:
                if i <= M:
                    s += 1
                    if s >= k:
                        s = 0
                        c += 1
                else:
                    s = 0
            if c < m:
                L = M
            else:
                R = M
        if R == max(a) + 1:
            R = -1
        return R