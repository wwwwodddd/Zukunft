// https://leetcode.com/problems/two-sum

class Solution(object):
    def twoSum(self, nums, target):
        a = sorted(nums)
        i = 0
        j = len(a) - 1
        while i < j:
            if a[i] + a[j] == target:
                x = nums.index(a[i])
                nums[x] = -62626262
                y = nums.index(a[j])
                if x > y:
                    x, y = y, x
                return [x + 1, y + 1]
            elif a[i] + a[j] < target:
                i += 1
            elif a[i] + a[j] > target:
                j -= 1
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        