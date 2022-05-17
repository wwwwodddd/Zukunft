class Solution(object):
    def repeatedSubstringPattern(self, str):
        n = len(str)
        for i in range(1, n):
            if n % i == 0 and str[i:] == str[:-i]:
                return True
        return False
        """
        :type str: str
        :rtype: bool
        """
        