class Solution:
    def maximumCandies(self, a: List[int], k: int) -> int:
        L = 0
        R = max(a) + 1
        while L < R - 1:
            M = (L + R) // 2
            s = 0
            for i in a:
                s += i // M
            if s >= k:
                L = M
            else:
                R = M
        return L