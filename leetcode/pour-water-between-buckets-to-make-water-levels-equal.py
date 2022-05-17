class Solution:
    def equalizeWater(self, a: List[int], p: int) -> float:
        p = (100 - p) / 100
        L = 0
        R = 1e5
        for i in range(50):
            M = (L + R) / 2
            s = 0
            t = 0
            for i in a:
                if i < M:
                    t += M - i
                else:
                    s += i - M
            if s * p >= t:
                L = M
            else:
                R = M
        return L