class Solution:
    def maximumSwap(self, n: int) -> int:
        a = list(str(n))
        z = n
        for i in range(len(a)):
            for j in range(i):
                a[i], a[j] = a[j], a[i]
                z = max(z, int(''.join(a)))
                a[i], a[j] = a[j], a[i]
        return z