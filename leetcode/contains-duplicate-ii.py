class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        nums = [(y, x) for x, y in enumerate(nums)]
        nums.sort()
        for i in range(1, len(nums)):
            if nums[i - 1][0] == nums[i][0] and nums[i][1] - nums[i - 1][1] <= k:
                    return True
        return False