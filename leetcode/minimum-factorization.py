class Solution:
    def smallestFactorization(self, n: int) -> int:
        z = ''
        if n == 1:
            z = '1'
        for i in range(9,1,-1):
            while n % i == 0:
                n //= i
                z += str(i)
        if n > 1:
            z = '0'
        z = int(z[::-1])
        if z >= 2 ** 31:
            z = 0
        return z