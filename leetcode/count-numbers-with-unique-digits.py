class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        z = 1
        t = 1
        for i in range(n):
            if i == 0:
                t *= 9
            else:
                t *= 10 - i
            z += t
        return z
                
