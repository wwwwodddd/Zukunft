class Solution:
    def minCost(self, a: str, b: List[int]) -> int:
        z = s = m = l = 0
        for i in range(len(a)):
            if l != a[i]:
                z += s - m
                s = 0
                m = 0
                l = a[i]
            s += b[i]
            m = max(m, b[i])
        z += s - m
        s = 0
        m = 0
        return z