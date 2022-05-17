class Solution(object):
    def minMoves(self, nums):
        nums = sorted(nums)
        
        ans = 0
        for i in nums:
            ans += i - nums[0]
        return ans
        """
        :type nums: List[int]
        :rtype: int
        """