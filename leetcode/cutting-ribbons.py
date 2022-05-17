class Solution:
    def maxLength(self, a: List[int], k: int) -> int:
        L = 0
        R = max(a) + 1
        while L < R - 1:
            M = (L + R) // 2
            c = 0
            for i in a:
                c += i // M
            if c >= k:
                L = M
            else:
                R = M
        return L