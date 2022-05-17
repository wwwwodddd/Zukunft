class Solution:
    def removeStones(self, a: List[List[int]]) -> int:
        n = len(a)
        z = 0
        f = list(range(n))
        def F(x):
            if f[x] == x:
                return x
            f[x] = F(f[x])
            return f[x]
        def U(x, y):
            nonlocal z
            x = F(x)
            y = F(y)
            if x != y:
                f[x] = y
                z += 1
        x = {}
        y = {}
        for i in range(n):
            if a[i][0] in x:
                U(x[a[i][0]], i)
            else:
                x[a[i][0]] = i
            if a[i][1] in y:
                U(y[a[i][1]], i)
            else:
                y[a[i][1]] = i
        return z