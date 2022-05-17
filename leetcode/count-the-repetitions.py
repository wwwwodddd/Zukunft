class Solution:
    def getMaxRepetitions(self, s1: str, n1: int, s2: str, n2: int) -> int:
        l1 = len(s1)
        l2 = len(s2)
        a = [(0, i) for i in range(l2)]
        b = a.copy()
        for i in range(l2):
            p = i
            for j in range(l1):
                if s1[j] == s2[p % l2]:
                    p += 1
            b[i] = (p // l2, p % l2)

        def mul(a, b):
            c = [(0, i) for i in range(len(a))]
            for i in range(len(a)):
                c[i] = (a[i][0] + b[a[i][1]][0], b[a[i][1]][1])
            return c

        while n1:
            if n1 & 1:
                a = mul(a, b)
            b = mul(b, b)
            n1 >>= 1
        return a[0][0] // n2