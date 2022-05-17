class Solution:
    def spiralMatrixIII(self, n: int, m: int, x: int, y: int) -> List[List[int]]:
        z = [(x, y)]
        for d in range(1, max(n, m)):
            for i in range(2 * d):
                xx = x + i - d + 1
                yy = y + d
                if 0 <= xx < n and 0 <= yy < m:
                    z.append((xx, yy))
            for i in range(2 * d):
                xx = x + d
                yy = y + d - 1 - i
                if 0 <= xx < n and 0 <= yy < m:
                    z.append((xx, yy))
            for i in range(2 * d):
                xx = x + d - 1 - i
                yy = y - d
                if 0 <= xx < n and 0 <= yy < m:
                    z.append((xx, yy))
            for i in range(2 * d):
                xx = x - d
                yy = y + i - d + 1
                if 0 <= xx < n and 0 <= yy < m:
                    z.append((xx, yy))
        return z