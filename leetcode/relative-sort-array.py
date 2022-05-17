class Solution:
    def relativeSortArray(self, a: List[int], b: List[int]) -> List[int]:
        return sorted(a,key=lambda x:(b+sorted(a)).index(x))