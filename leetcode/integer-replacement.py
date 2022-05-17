class Solution(object):
    def integerReplacement(self, n):
        if n == 1:
            return 0
        if n % 2 == 0:
            return self.integerReplacement(n / 2) + 1
        if n % 2 == 1:
            return min(self.integerReplacement(n + 1), self.integerReplacement(n - 1)) + 1
        """
        :type n: int
        :rtype: int
        """