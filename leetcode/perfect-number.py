class Solution:
    def checkPerfectNumber(self, n: int) -> bool:
        i = 1
        s = 0
        while i * i <= n:
            if n % i == 0:
                s += i
                if i * i < n:
                    s += n // i
            i += 1
        return s == 2 * n