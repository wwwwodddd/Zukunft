class Solution:
    def countCornerRectangles(self, a: List[List[int]]) -> int:
        n = len(a)
        m = len(a[0])
        z = 0
        for i in range(n):
            for j in range(i):
                c = 0
                for k in range(m):
                    if a[i][k] == 1 and a[j][k] == 1:
                        z += c
                        c += 1
        return z