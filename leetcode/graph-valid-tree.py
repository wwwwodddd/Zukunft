class Solution:
    def validTree(self, n: int, e: List[List[int]]) -> bool:
        if len(e) != n - 1:
            return False
        f = list(range(n))
        def F(x):
            if f[x] == x:
                return x
            f[x] = F(f[x])
            return f[x]
        for x, y in e:
            if F(x) == F(y):
                return False
            f[F(x)] = F(y)
        return True