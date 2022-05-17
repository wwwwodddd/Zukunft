class Solution:
    def maximumBobPoints(self, m: int, a: List[int]) -> List[int]:
        n = 12
        z = -1
        p = []
        for i in range(1 << n):
            s = 0
            b = [0 for j in range(n)]
            for j in range(n):
                if i >> j & 1:
                    b[j] = a[j] + 1
                    s += j
            if sum(b) <= m:
                b[0] += m - sum(b)
                if z < s:
                    z = s
                    p = b
        return p