class Solution:
    def smallestRangeI(self, a: List[int], k: int) -> int:
        return max(max(a)-min(a)-2*k,0)