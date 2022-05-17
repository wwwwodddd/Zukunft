class Solution:
    def numFactoredBinaryTrees(self, a: List[int]) -> int:
        p = 1000000007
        a.sort()
        n = len(a)
        b = {a[i]:i for i in range(n)}
        f = [0] * n
        for i in range(n):
            f[i] = 1
            for j in range(i):
                if a[i] % a[j] == 0 and a[i] // a[j] in b:
                    f[i] = (f[i] + f[j] * f[b[a[i] // a[j]]]) % p
        return sum(f) % p