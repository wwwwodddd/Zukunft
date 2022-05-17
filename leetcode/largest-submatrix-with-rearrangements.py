class Solution:
    def largestSubmatrix(self, a: List[List[int]]) -> int:
        n = len(a)
        m = len(a[0])
        b = [0] * m
        z = 0
        for i in range(n):
            for j in range(m):
                if a[i][j] == 1:
                    b[j] += 1
                else:
                    b[j] = 0
            c = sorted(b,reverse=True)
            for i in range(m):
                z = max(z, (i + 1) * c[i])
        return z