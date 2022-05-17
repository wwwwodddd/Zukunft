class Solution:
    def smallerNumbersThanCurrent(self, a: List[int]) -> List[int]:
        return [sum(j < i for j in a)for i in a]