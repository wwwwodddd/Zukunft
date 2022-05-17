class Solution:
    def countDifferentSubsequenceGCDs(self, a: List[int]) -> int:
        m = max(a) + 1
        c = [0] * m
        for i in a:
            c[i] = 1
        z = 0
        for i in range(1, m):
            g = 0
            for j in range(i, m, i):
                if c[j]:
                    g = gcd(g, j)
            if g == i:
                z += 1
        return z