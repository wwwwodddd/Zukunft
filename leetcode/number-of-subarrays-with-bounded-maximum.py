class Solution:
    def numSubarrayBoundedMax(self, a: List[int], l: int, r: int) -> int:
        def zou(a, m):
            z = c = 0
            for i in a:
                if i <= m:
                    c += 1
                    z += c
                else:
                    c = 0
            return z
        return zou(a, r) - zou(a, l - 1)