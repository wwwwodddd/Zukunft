class Solution(object):
    def minMoves2(self, nums):
        nums = sorted(nums)
        x = nums[len(nums) / 2]
        ans = 0
        for i in nums:
            ans += abs(x - i)
        return ans
        """
        :type nums: List[int]
        :rtype: int
        """