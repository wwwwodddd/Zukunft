class Solution(object):
    def reverseWords(self, s):
        return ' '.join(s.split()[::-1])
        """
        :type s: str
        :rtype: str
        """
        