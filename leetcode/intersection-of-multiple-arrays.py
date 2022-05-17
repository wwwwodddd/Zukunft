class Solution:
    def intersection(self, a: List[List[int]]) -> List[int]:
        a = map(set, a)
        b = set.intersection(*a)
        return sorted(list(b))