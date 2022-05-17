class Solution(object):
    def getRow(self, rowIndex):
        re = [0] * (rowIndex + 1)
        re[0] = 1
        for i in range(rowIndex):
            for j in range(rowIndex, 0, -1):
                re[j] += re[j - 1]
        return re
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        