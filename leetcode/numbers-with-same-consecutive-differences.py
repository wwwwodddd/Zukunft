class Solution:
    def numsSameConsecDiff(self, n: int, k: int) -> List[int]:
        f = list(range(1,10))
        for i in range(1, n):
            g = []
            for j in f:
                if j % 10 + k < 10:
                    g.append(j * 10 + j % 10 + k)
                if k and j % 10 - k >= 0:
                    g.append(j * 10 + j % 10 - k)
            f = g
        return f