class Solution:
    def prisonAfterNDays(self, a: List[int], n: int) -> List[int]:
        def F(a):
            b = [0 for i in range(8)]
            for i in range(1, 7):
                if a[i-1] == a[i+1]:
                    b[i] = 1
            return tuple(b)
        a = tuple(a)
        g = {a : 0}
        i = 0
        while i < n:
            a = F(a)
            i += 1
            if a in g:
                d = i - g[a]
                i += (n - i) // d * d
            else:
                g[a] = i
        return a