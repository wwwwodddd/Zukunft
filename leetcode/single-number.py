class Solution(object):
    def singleNumber(self, nums):
        return reduce(int.__xor__, nums)
        """
        :type nums: List[int]
        :rtype: int
        """
        