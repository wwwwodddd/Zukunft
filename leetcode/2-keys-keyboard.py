class Solution:
    def minSteps(self, n: int) -> int:
        i = 2
        z = 0
        while i * i <= n:
            while n % i == 0:
                z += i
                n //= i
            i += 1
        if n > 1:
            z += n
        return z