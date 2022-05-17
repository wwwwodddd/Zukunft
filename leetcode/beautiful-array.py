class Solution:
    def beautifulArray(self, n: int) -> List[int]:
        def F(n):
            if n == 1:
                return [1]
            l = F(n // 2)
            r = F((n + 1) // 2)
            z = []
            for i in l:
                z.append(i * 2)
            for i in r:
                z.append(i * 2 - 1)
            return z
        return F(n)