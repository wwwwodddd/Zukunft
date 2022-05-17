def F(n):
    s = 0
    for i in str(n):
        s += int(i)**2
    return s
class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        a = F(n)
        b = n
        while a != b:
            a = F(F(a))
            b = F(b)
        return a == 1