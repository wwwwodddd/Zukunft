class Solution:
    def arrayNesting(self, a: List[int]) -> int:
        n = len(a)
        v = [0] * n
        z = 0
        for i in range(n):
            c = 0
            while v[i] == 0:
                v[i] = 1
                i = a[i]
                c += 1
            z = max(z, c)
        return z