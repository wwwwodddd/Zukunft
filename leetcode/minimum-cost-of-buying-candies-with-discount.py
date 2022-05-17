class Solution:
    def minimumCost(self, a: List[int]) -> int:
        a.sort(reverse=True)
        return sum(a) - sum(a[2::3])