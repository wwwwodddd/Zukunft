class Solution(object):
    def myAtoi(self, str):
        str = str.strip()
        for i in range(len(str)):
            if str[i] == '-' or str[i] == '+' or (ord('0') <= ord(str[i]) and ord(str[i]) <= ord('9')):
                pass
            else:
                str = str[:i]
                break
        if str == '':
            return 0
        try:
            x = int(str)
            if x > 2147483647:
                return 2147483647
            if x < -2147483648:
                return -2147483648
            return x
        except:
            return 0
        """
        :type str: str
        :rtype: int
        """
        