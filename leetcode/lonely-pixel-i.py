class Solution:
    def findLonelyPixel(self, a: List[List[str]]) -> int:
        n = len(a)
        m = len(a[0])
        r = [0] * n
        c = [0] * m
        for i in range(n):
            for j in range(m):
                if a[i][j] == 'B':
                    r[i] += 1
                    c[j] += 1
        z = 0
        for i in range(n):
            for j in range(m):
                if a[i][j] == 'B' and r[i] == 1 and c[j] == 1:
                    z += 1
        return z