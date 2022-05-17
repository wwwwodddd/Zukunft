class Solution:
    def reinitializePermutation(self, n: int) -> int:
        v = [0] * n
        z = 1
        for i in range(n):
            c = 0
            j = i
            while True:
                if j % 2 == 0:
                    j //= 2
                else:
                    j = n // 2 + (j - 1) // 2
                c += 1
                if j == i:
                    break
            z = z * c // gcd(z, c)
        return z