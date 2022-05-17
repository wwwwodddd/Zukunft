class Solution:
    def luckyNumbers (self, a: List[List[int]]) -> List[int]:
        return list(set(map(min,a))&set(map(max,zip(*a))))