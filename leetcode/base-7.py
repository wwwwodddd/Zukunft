class Solution:
    def convertToBase7(self, n: int) -> str:
        if n < 0:
            return '-' + self.convertToBase7(-n)
        if n < 7:
            return str(n)
        return self.convertToBase7(n // 7) + str(n % 7)