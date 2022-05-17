class Solution:
    def maxCount(self, m: int, n: int, o: List[List[int]]) -> int:
        x,y=map(min,zip(*(o+[[m,n]])))
        return x*y