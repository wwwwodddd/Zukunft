class Solution:
    def maxScoreIndices(self, nums: List[int]) -> List[int]:
        c = nums.count(1)
        zc = c
        zi = [0]
        for i in range(len(nums)):
            if nums[i] == 1:
                c -= 1
            else:
                c += 1
            if zc < c:
                zc = c
                zi = [i + 1]
            elif zc == c:
                zi.append(i + 1)
        return zi