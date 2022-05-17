class Solution:
    def minimumSize(self, a: List[int], o: int) -> int:
        L = 0
        R = max(a)
        while L < R - 1:
            M = (L + R) // 2
            s = 0
            for i in a:
                s += (i - 1) // M
            if s <= o:
                R = M
            else:
                L = M
        return R