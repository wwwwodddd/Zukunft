class Solution:
    def longestLine(self, a: List[List[int]]) -> int:
        z = 0
        n = len(a)
        m = len(a[0])
        for i in range(n):
            s = 0
            for j in range(m):
                if a[i][j]:
                    s += 1
                    z = max(z, s)
                else:
                    s = 0

        for j in range(m):
            s = 0
            for i in range(n):
                if a[i][j]:
                    s += 1
                    z = max(z, s)
                else:
                    s = 0

        for i in range(n):
            s = 0
            for j in range(min(m, n - i)):
                if a[i + j][j]:
                    s += 1
                    z = max(z, s)
                else:
                    s = 0
        for j in range(m):
            s = 0
            for i in range(min(n, m - j)):
                if a[i][j + i]:
                    s += 1
                    z = max(z, s)
                else:
                    s = 0

        for i in range(n):
            s = 0
            for j in range(min(m, n - i)):
                if a[i + j][m - 1 - j]:
                    s += 1
                    z = max(z, s)
                else:
                    s = 0
        for j in range(m):
            s = 0
            for i in range(min(n, m - j)):
                if a[i][m - 1 - j - i]:
                    s += 1
                    z = max(z, s)
                else:
                    s = 0
        
        return z