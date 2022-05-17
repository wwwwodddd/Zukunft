class Solution:
    def countElements(self, a: List[int]) -> int:
        mn = min(a)
        mx = max(a)
        return sum(mn<i<mx for i in a)