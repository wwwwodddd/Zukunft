class Solution:
    def transpose(self, a: List[List[int]]) -> List[List[int]]:
        return list(zip(*a))