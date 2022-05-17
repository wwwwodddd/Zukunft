class Solution:
    def maximumWealth(self, a: List[List[int]]) -> int:
        return max(sum(i)for i in a)