class Solution(object):
    def findDuplicate(self, nums):
        n = len(nums) - 1
        l = 0
        r = n
        while l < r - 1:
            m = (l + r) / 2
            cnt = 0
            for i in nums:
                if i <= m:
                    cnt += 1
            if cnt <= m:
                l = m
            else:
                r = m
        return r
        """
        :type nums: List[int]
        :rtype: int
        """
        