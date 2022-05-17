class Solution:
    def intersection(self, a: List[int], b: List[int]) -> List[int]:
        return list(set(a) & set(b))