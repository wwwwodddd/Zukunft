class Solution:
    def minElements(self, a: List[int], l: int, g: int) -> int:
        return (abs(g - sum(a)) + l - 1) // l