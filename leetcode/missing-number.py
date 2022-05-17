class Solution(object):
    def missingNumber(self, nums):
        z = 0
        for i in nums:
            z ^= i
        for i in range(len(nums) + 1):
            z ^= i
        return z
        """
        :type nums: List[int]
        :rtype: int
        """
        