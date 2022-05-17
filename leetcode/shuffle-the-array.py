class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        re = []
        for i in range(n):
            re.append(nums[i])
            re.append(nums[i + n])
        return re