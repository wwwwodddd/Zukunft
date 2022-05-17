class Solution(object):
    def divide(self, dividend, divisor):
        s = int(dividend.__truediv__(divisor))
        if s >= 2 ** 31:
            return 2 ** 31 - 1
        if s < -2 ** 31:
            return -2 ** 31
        return s
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        