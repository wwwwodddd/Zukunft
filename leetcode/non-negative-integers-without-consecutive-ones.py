class Solution:
    def findIntegers(self, n: int) -> int:
        n += 1
        f = [1, 2]
        for i in range(40):
            f.append(f[-1] + f[-2])
        a = []
        while n:
            a.append(n % 2)
            n //= 2
        z = 0
        for i in range(len(a))[::-1]:
            if a[i] == 1:
                z += f[i]
                if i + 1 < len(a) and a[i + 1] == 1:
                    break
        return z