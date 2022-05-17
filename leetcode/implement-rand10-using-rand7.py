# The rand7() API is already defined for you.
# def rand7():
# @return a random integer in the range 1 to 7

class Solution:
    def rand10(self):
        """
        :rtype: int
        """
        while True:
            d = rand7() * 7 + rand7() - 8
            if d < 40:
                return d % 10 + 1