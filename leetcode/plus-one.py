class Solution(object):
    def plusOne(self, digits):
        digits = digits[::-1]
        digits[0] += 1
        digits.append(0)
        for i in range(len(digits) - 1):
            digits[i + 1] += digits[i] / 10
            digits[i] %= 10
        if digits[-1] == 0:
            del digits[-1]
        digits = digits[::-1]
        return digits
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        