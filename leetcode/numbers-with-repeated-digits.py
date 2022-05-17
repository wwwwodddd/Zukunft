class Solution:
    def numDupDigitsAtMostN(self, n: int) -> int:
        z = n
        n += 1
        a = []
        while n:
            a.append(n % 10)
            n //= 10
        v = set()
        c = 9
        for i in range(1, len(a)):
            z -= c
            c *= 10 - i
        for i in range(len(a))[::-1]:
            for j in range(i == len(a) - 1, a[i]):
                if j not in v:
                    z -= math.perm(10 - 1 - len(v), i)
            if a[i] in v:
                break
            v.add(a[i])
        return z