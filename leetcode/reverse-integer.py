class Solution(object):
    def reverse(self, x):
        if x < 0:
            return -self.reverse(-x)
        fuckyou = int(''.join(str(x)[::-1]))
        if fuckyou < -2**31 or fuckyou >= 2 ** 31:
            return 0
        return fuckyou
        
        """
        :type x: int
        :rtype: int
        """
        