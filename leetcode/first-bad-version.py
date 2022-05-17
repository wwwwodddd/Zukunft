# The isBadVersion API is already defined for you.
# @param version, an integer
# @return an integer
# def isBadVersion(version):

class Solution:
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        z = 0
        for i in range(31)[::-1]:
            if z + 2 ** i <= n and not isBadVersion(z + 2 ** i):
                z += 2 ** i
        return z + 1