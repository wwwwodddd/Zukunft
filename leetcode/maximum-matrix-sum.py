class Solution:
    def maxMatrixSum(self, a: List[List[int]]) -> int:
        b = []
        c = 0
        for i in a:
            for j in i:
                if j > 0:
                    b.append(j)
                else:
                    b.append(-j)
                    c ^= 1
        b.sort()
        if c:
            b[0] = -b[0]
            c ^= 1
        return sum(b)