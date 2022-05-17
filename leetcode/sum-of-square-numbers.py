class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        a = 0
        while a * a <= c:
            b = int(sqrt(c - a * a))
            if a * a + b * b == c:
                return True
            a += 1
        return False