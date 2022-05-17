class Solution:
    def minTotalDistance(self, a: List[List[int]]) -> int:
        n = len(a)
        m = len(a[0])
        x = []
        y = []
        for i in range(n):
            for j in range(m):
                if a[i][j] == 1:
                    x.append(i)
                    y.append(j)
        x.sort()
        y.sort()
        z = 0
        for i in range(len(x)):
            z += abs(x[i] - x[len(x) // 2])
            z += abs(y[i] - y[len(y) // 2])
        return z
