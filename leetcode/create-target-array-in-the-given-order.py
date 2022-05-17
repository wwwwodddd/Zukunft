class Solution:
    def createTargetArray(self, nums: List[int], index: List[int]) -> List[int]:
        a = []
        for i in range(len(nums)):
            a.insert(index[i], nums[i])
        return a