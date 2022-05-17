class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        j = 0
        z = 0
        s = 0
        for i in range(len(nums)):
            if nums[i] == 0:
                s += 1
            while s > k:
                if nums[j] == 0:
                    s -= 1
                j += 1
            z = max(z, i - j + 1)
        return z