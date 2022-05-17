class Solution:
    def findDifference(self, a: List[int], b: List[int]) -> List[List[int]]:
        return [list(set(a) - set(b)), list(set(b) - set(a))]