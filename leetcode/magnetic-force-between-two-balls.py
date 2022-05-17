class Solution:
    def maxDistance(self, a: List[int], m: int) -> int:
        a.sort()
        L = 0
        R = 10**10
        while L < R - 1:
            M = (L + R) // 2
            c = 0
            p = 0
            for i in a:
                if p <= i:
                    p = i + M
                    c += 1
            if c >= m:
                L = M
            else:
                R = M
        return L