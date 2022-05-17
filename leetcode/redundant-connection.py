class Solution:
    def findRedundantConnection(self, e: List[List[int]]) -> List[int]:
        n = len(e)
        f = [i for i in range(n + 1)]
        def F(x):
            if f[x] == x:
                return x
            f[x] = F(f[x])
            return f[x]
        for x, y in e:
            if F(x) == F(y):
                return [x, y]
            else:
                f[F(x)] = F(y)