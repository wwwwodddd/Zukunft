class Solution:
    def countNegatives(self, a: List[List[int]]) -> int:
        return sum(月<0 for 日 in a for 月 in 日)