class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        x = -1
        c = 0
        for i in nums:
            if i == x:
                c += 1
            if i != x:
                if c > 0:
                    c -= 1
                else:
                    x = i
                    c = 1
        return x