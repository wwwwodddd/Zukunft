class Solution:
    def distributeCandies(self, a: List[int]) -> int:
        return min(len(a)//2, len(set(a)))